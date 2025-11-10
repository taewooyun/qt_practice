# CMake 최소 요구 버전 지정
cmake_minimum_required(VERSION 3.16)

# 프로젝트 이름, 버전, 사용 언어 설정
project(daily_project VERSION 0.1 LANGUAGES CXX)

# Qt 자동화 설정
# UIC (User Interface Compiler): .ui 파일 자동 변환
set(CMAKE_AUTOUIC ON)
# MOC (Meta-Object Compiler): signals/slots 등 Qt 확장 문법 자동 처리
set(CMAKE_AUTOMOC ON)
# RCC (Resource Compiler): .qrc 리소스 파일 자동 처리
set(CMAKE_AUTORCC ON)

# C++ 표준 설정 (C++17 필수)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt 버전에 따라 Widgets 모듈 찾기 (Qt5 또는 Qt6 호환)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# 프로젝트에 포함될 소스 목록 정의
set(PROJECT_SOURCES
    main.cpp       # 진입점
    widget.cpp     # 위젯 클래스 구현부
    widget.h       # 위젯 클래스 헤더
    widget.ui      # Qt Designer로 만든 UI 파일
)

# Qt 6 이상 버전일 경우 qt_add_executable() 사용
# (Qt6에서는 qt_add_executable을 통해 자동 처리)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(daily_project
        MANUAL_FINALIZATION      # 수동으로 qt_finalize_executable() 호출 필요
        ${PROJECT_SOURCES}
    )

# Qt 5 이하 버전용 (Qt 6 이전 버전에서는 add_executable/add_library 사용)
else()
    if(ANDROID)
        # Android 빌드일 경우 공유 라이브러리(.so)로 빌드
        add_library(daily_project SHARED
            ${PROJECT_SOURCES}
        )
        # ANDROID_PACKAGE_SOURCE_DIR 경로 설정 예시 (주석)
        # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        # 일반 데스크탑 환경 빌드 (Windows/Linux/macOS)
        add_executable(daily_project
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Qt 위젯 모듈과 링크 (QtCore, QtGui, QtWidgets 등)
target_link_libraries(daily_project PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# macOS/iOS용 번들 ID 설정 (앱 서명 및 배포 시 필요)
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.daily_project)
endif()

# 타겟 속성 설정
# - macOS 번들 식별자
# - 버전 정보
# - GUI 실행 파일 여부
set_target_properties(daily_project PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE             # macOS .app 번들 생성
    WIN32_EXECUTABLE TRUE          # Windows 콘솔창 없는 GUI 실행 파일
)

# 설치 경로 설정
include(GNUInstallDirs)
install(TARGETS daily_project
    BUNDLE DESTINATION .           # macOS 번들 설치 경로
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}  # Linux용 라이브러리 경로
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}  # 실행 파일 설치 경로
)

# Qt6에서는 qt_finalize_executable()로 빌드 마무리 단계 수행
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(daily_project)
endif()

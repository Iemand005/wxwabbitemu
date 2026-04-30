# Portions of this come from KiCad's CMakeLists.txt

cmake_minimum_required(VERSION 3.10.0)

# set the project name
project(wxWabbitemu VERSION 0.1.0)

# find wx + include it
# Turn on wxWidgets compatibility mode for some classes
add_definitions( -DWX_COMPATIBILITY )

# Don't link statically
set( wxWidgets_CONFIG_OPTIONS ${wxWidgets_CONFIG_OPTIONS} --static=no )

# now hunt for wxWidgets
# (adv is used for "advanced" widgets, such as the wizard)
# find_package(wxWidgets REQUIRED adv net core base)
# include(${wxWidgets_USE_FILE})

set(wxBUILD_SHARED OFF CACHE BOOL "" FORCE)

set(wxBUILD_SHARED OFF CACHE BOOL "Build static libs for smaller distribution")
set(wxBUILD_TESTS OFF CACHE STRING "No tests")
set(wxBUILD_SAMPLES OFF CACHE STRING "No samples")
set(wxBUILD_DEMOS OFF CACHE BOOL "No demos")
set(wxBUILD_MONOLITHIC OFF CACHE BOOL "Keep libraries separate to link only what is needed")
set(wxBUILD_PRECOMP ON CACHE BOOL "Keep this ON to speed up the build")

set(wxUSE_AUI OFF CACHE BOOL "Disable AUI")
set(wxUSE_HTML OFF CACHE BOOL "Disable HTML")
set(wxUSE_WEBVIEW OFF CACHE BOOL "Disable WebView")
set(wxUSE_MEDIACTRL OFF CACHE BOOL "Disable MediaCtrl")
set(wxUSE_RICHTEXT OFF CACHE BOOL "Disable RichText")
set(wxUSE_LIBJPEG OFF CACHE BOOL "Disable JPEG support")
set(wxUSE_LIBTIFF OFF CACHE BOOL "Disable TIFF support")
set(wxUSE_EXPAT   OFF CACHE BOOL "Disable XML parsing (Expat)")
set(wxUSE_ZLIB    OFF CACHE BOOL "Disable Zlib compression")
set(wxUSE_LIBJPEG OFF CACHE BOOL "" FORCE)
set(wxUSE_LIBTIFF OFF CACHE BOOL "" FORCE)
set(wxUSE_EXPAT   OFF CACHE BOOL "" FORCE)
set(wxUSE_WEBVIEW OFF CACHE BOOL "" FORCE)
set(wxUSE_NANOSVG OFF CACHE BOOL "" FORCE)
set(wxUSE_LIBWEBP OFF CACHE BOOL "" FORCE)
set(wxUSE_REGEX   OFF CACHE BOOL "" FORCE)
set(wxUSE_ARTPROVIDER_TANGO OFF CACHE BOOL "" FORCE)
set(wxUSE_ARTPROVIDER_STD   OFF CACHE BOOL "" FORCE)
set(wxUSE_GIF OFF CACHE BOOL "" FORCE)
set(wxUSE_GIF OFF CACHE BOOL "" FORCE)
set(wxUSE_PNM       OFF CACHE BOOL "" FORCE)
set(wxUSE_PCX       OFF CACHE BOOL "" FORCE)
set(wxUSE_IFF       OFF CACHE BOOL "" FORCE)
set(wxUSE_TGA       OFF CACHE BOOL "" FORCE)
set(wxUSE_XPM       OFF CACHE BOOL "" FORCE)
set(wxUSE_SVG       OFF CACHE BOOL "" FORCE)

set(wxUSE_DRAGIMAGE OFF CACHE BOOL "" FORCE)
set(wxUSE_TREELISTCTRL OFF CACHE BOOL "" FORCE)
set(wxUSE_BITMAPCOMBOBOX OFF CACHE BOOL "" FORCE)
set(wxUSE_TOOLBOOK    OFF CACHE BOOL "" FORCE)
set(wxUSE_AUIPANEINFO OFF CACHE BOOL "" FORCE)
set(wxUSE_BUTTONBAR   OFF CACHE BOOL "" FORCE)
set(wxUSE_TREEBOOK    OFF CACHE BOOL "" FORCE)
set(wxUSE_DOC_VIEW_FRAMEWORK OFF CACHE BOOL "" FORCE)
set(wxUSE_PRINTING_ARCHITECTURE OFF CACHE BOOL "" FORCE)

set(wxUSE_ZLIB builtin CACHE BOOL "" FORCE)
set(wxUSE_IMAGE ON CACHE BOOL "" FORCE)
set(wxUSE_LIBPNG builtin CACHE BOOL "" FORCE)
set(wxUSE_TOOLBAR ON CACHE BOOL "" FORCE)
set(wxUSE_TOOLBAR_NATIVE ON CACHE BOOL "" FORCE)

add_subdirectory(external/wxWidgets)
include_directories(external/wxWidgets/include)

add_subdirectory(external/spasm-ng)

# Only build static lib for EFSW
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Disable shared library" FORCE)
set(BUILD_STATIC_LIBS ON CACHE BOOL "Enable static library" FORCE)
set(BUILD_TEST_APP OFF CACHE BOOL "Disable test application" FORCE)
set(EFSW_INSTALL OFF CACHE BOOL "Disable install targets" FORCE)
set(VERBOSE OFF CACHE BOOL "Disable verbose mode" FORCE)
add_subdirectory(external/efsw)


# Make MSVC shut up
if(MSVC)
	add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
	add_compile_options(/wd4996)
	set(VCPKG_MANIFEST_MODE OFF CACHE BOOL "" FORCE)
	set(VCPKG_TARGET_TRIPLET "" CACHE STRING "" FORCE)
	add_compile_options(/TP)
	add_compile_options("$<$<COMPILE_LANGUAGE:C>:/TP>")
	add_compile_options("$<$<COMPILE_LANGUAGE:CXX>:/TP>")
endif()

# mixing of C and C++ necessitates builds in c++
file(GLOB_RECURSE CFILES "${CMAKE_SOURCE_DIR}/*.c")
set_source_files_properties(${CFILES} PROPERTIES LANGUAGE CXX )

if(WIN32)
    set(RESOURCES resource.rc)
else()
    set(RESOURCES "")
endif()

# add the executable
add_executable(wxWabbitemu
	#[[ Core ]]
	core/core.c
	core/alu.c
	core/control.c
	core/device.c
	core/indexcb.c
	
	#[[ Calc Interfacing ]]
	interface/calc.c
	interface/state.c
	
	#[[ Utilities/Libraries ]]
	utilities/exportvar.c
	utilities/fileutilities.c
	utilities/gif.c
	utilities/gifhandle.c
	utilities/label.c
	utilities/savestate.c
	utilities/sendfile.c
	utilities/var.c
	#[[ Hardware Emulation ]]
	hardware/81hw.c
	hardware/83hw.c
	hardware/83phw.c
	hardware/83psehw.c
	hardware/86hw.c
	hardware/keys.c
	hardware/lcd.c
	hardware/link.c
	#[[ wxWidgets GUI ]]
	gui/gui.cpp #[[ This requires gui/gui.h ]]
	gui/guiapp.cpp #[[ This requires gui/guiapp.h ]]
	gui/guiskinwindow.cpp #[[ This requires gui/guiskinwindow.h ]]
	gui/guilcd.cpp #[[ This requires gui/guilcd.h ]]
	gui/guivartree.cpp #[[ This requires gui/guivartree.h ]]
	gui/droptarget.cpp #[[ This requires gui/droptarget.h ]]
	gui/wizard/wizardstart.cpp #[[ This requires gui/wizard/wizardstart.h ]]
	gui/wizard/wizardcalctype.cpp #[[ This requires gui/wizard/wizardcalctype.h ]]
	gui/wizard/wizardos.cpp #[[ This requires gui/wizard/wizardos.h ]]
	gui/wizard/romwizard.cpp #[[ This requires gui/wizard/romwizard.h ]]
	debugger/guidebug.cpp #[[ This requires debugger/guidebug.h ]]
	#[[ Debugger and debugger GUI ]]
	debugger/disassemblyview.cpp #[[ This requires debugger/disassemblyview.h ]]
	debugger/disassemble.c
	debugger/panes/regpane.cpp #[[ This requires debugger/panes/regpane.h ]]
	debugger/panes/flagspane.cpp #[[ This requires debugger/panes/flagspane.h ]]
	debugger/panes/cpupane.cpp #[[ This requires debugger/panes/cpupane.h ]]

	#[[ Resources for Windows ]]
	${RESOURCES}
)

target_include_directories(wxWabbitemu PUBLIC
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/core"
	"${PROJECT_SOURCE_DIR}/debugger"
	"${PROJECT_SOURCE_DIR}/gui"
	"${PROJECT_SOURCE_DIR}/hardware"
	"${PROJECT_SOURCE_DIR}/interface"
	"${PROJECT_SOURCE_DIR}/utilities"
)

# target_link_libraries(wxWabbitemu ${wxWidgets_LIBRARIES})
target_link_libraries(wxWabbitemu PRIVATE
	wx::core
	libspasm
	efsw
)

add_definitions(-DHIGH_SHADE_GIF -DVERBOSE -D_LINUX -DWXVER)

if(MSVC)
    set_target_properties(wxWabbitemu PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
		
		set(wxUSE_RC_MANIFEST ON CACHE BOOL "" FORCE)
    set(wxUSE_DPI_AWARE_MANIFEST "per-monitor" CACHE STRING "" FORCE)
endif()

# COFF error fix?
if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /INCREMENTAL:NO")
    set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "${CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO} /INCREMENTAL:NO")
    
    set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} /INCREMENTAL:NO")
    set(CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO "${CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO} /INCREMENTAL:NO")
endif()
if(MSVC)
    # set_target_properties(wxWabbitemu PROPERTIES LINK_FLAGS "/MANIFEST:NO")

    target_link_options(wxWabbitemu PRIVATE "/INCREMENTAL:NO")
endif()

# Enable Unicode
if( CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
	if( GCC_VERSION VERSION_EQUAL 4.8.0 OR GCC_VERSION VERSION_GREATER 4.8.0 )
		add_definitions(-D_UNICODE)
	endif()
endif()

# CPack for packaging
if( UNIX AND NOT APPLE )

    # Create a *.deb file:
    set( CPACK_GENERATOR "DEB" )
    set( CPACK_DEBIAN_PACKAGE_MAINTAINER "https://github.com/alberthdev/wxwabbitemu" )

    set( CPACK_PACKAGE_VERSION_MAJOR 0 )
    set( CPACK_PACKAGE_VERSION_MINOR 1 )
    set( CPACK_PACKAGE_VERSION_PATCH 0 )
    set( CPACK_PACKAGE_CONTACT Albert Huang <alberthdev@users.noreply.github.com> )
    set( CPACK_PACKAGE_DESCRIPTION_SUMMARY "wxWabbitemu built by CMake build system." )

    include( CPack )

endif()

install(TARGETS wxWabbitemu DESTINATION bin)

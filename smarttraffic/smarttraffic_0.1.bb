nherit cmake

DESCRIPTION = "smarttraffic demo"
LICENSE = "BSD"
SECTION = "smarttraffic"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/${LICENSE};md5=3775480a712fc46a69647678acb234cb"

# Dependencies.
DEPENDS := "opencv"

FILESPATH =+ "${WORKSPACE}/video_ai/smarttraffic/bin/:"

SRC_URI = "file://smarttraffic/"
INSANE_SKIP_${PN}-dev += "ldflags dev-elf dev-deps"
PACKAGES = "${PN}-dbg ${PN} ${PN}-dev"
S = "/home/turbox/wuqx0806/cs-610/apps_proc/src/video_ai/smarttraffic/"

# Install directries.
INSTALL_INCDIR := "${includedir}"
INSTALL_BINDIR := "${bindir}"
INSTALL_LIBDIR := "${libdir}"

EXTRA_OECMAKE += ""

FILES_${PN} += "${INSTALL_BINDIR}"
FILES_${PN} += "${INSTALL_LIBDIR}"

SOLIBS = ".so*"
FILES_SOLIBSDEV = ""
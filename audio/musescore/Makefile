PORTNAME=	${GH_PROJECT:tl}
DISTVERSIONPREFIX=	v
DISTVERSION=	4.5.1
CATEGORIES=	audio

PATCH_SITES=	https://github.com/musescore/MuseScore/commit/
PATCHFILES+=	05056ed19520060c3912a09a3adfa0927057f956.patch:-p1 # Fix build with Qt >= 6.9.0

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Free music composition & notation software
WWW=		https://musescore.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libasound.so:audio/alsa-lib \
		libasound_module_pcm_oss.so:audio/alsa-plugins

USES=		cmake compiler:c++11-lib desktop-file-utils localbase \
		pkgconfig qt:5 shared-mime-info
USE_QT=		concurrent core dbus declarative designer graphicaleffects gui \
		network networkauth opengl printsupport \
		quickcontrols quickcontrols2 svg \
		widgets x11extras xml xmlpatterns \
		buildtools:build linguisttools:build qmake:build testlib:build \
		uitools:build

USE_GITHUB=	yes
GH_PROJECT=	MuseScore
GH_TAGNAME=	v4.5

# Each release gets a subdir containing the distfiles for that release,
# so hope that scanning the parent dir finds new ones.
#
# Note needs PORTVERSION:R once there is a .minor version
DATADIR=	${PREFIX}/share/mscore-${PORTVERSION:R}

CMAKE_OFF=	MUE_BUILD_CRASHPAD_CLIENT \
		MUE_COMPILE_USE_PCH
CMAKE_BUILD_TYPE=	release

post-install:
	# workaround for https://github.com/musescore/MuseScore/issues/26103
	@${RM} -r \
		${STAGEDIR}${PREFIX}/include \
		${STAGEDIR}${PREFIX}/lib \
		${STAGEDIR}${PREFIX}/libdata
	# workaround for https://github.com/musescore/MuseScore/issues/26104
	@${INSTALL_DATA} ${FILESDIR}/mscore.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@${REINPLACE_CMD} -e "\
		s|^Version=.*|Version=${PORTVERSION}|; \
		s|^Name=.*|Name=MuseScore|; \
		"  ${STAGEDIR}${PREFIX}/share/applications/mscore.desktop

.include <bsd.port.mk>

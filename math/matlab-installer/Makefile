PORTNAME=	matlab-installer
PORTVERSION=	0.2
PORTREVISION=	5
CATEGORIES=	math science java
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Easy installation of Linux Matlab(r) on FreeBSD
WWW=		https://acadix.biz/matlab-installer.php

LICENSE=	BSD3CLAUSE

DEPRECATED=     Unmaintained, does not support recent Matlab
EXPIRATION_DATE=2025-04-03

RUN_DEPENDS=	mount_image:sysutils/diskimage-tools \
		auto-ask:sysutils/auto-admin \
		webbrowser:www/webbrowser \

USES=		java linux tar:xz
USE_LINUX=	dri devtools
JAVA_OS=	linux

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/matlab-installer.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

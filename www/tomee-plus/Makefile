PORTNAME=	tomee
PORTVERSION=	10.0.0
CATEGORIES=	www java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	-plus
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}

MAINTAINER=	dmytro@posteo.net
COMMENT=	Open-source Jakarta EE application server by Apache based on Tomcat
WWW=		http://tomee.apache.org/

LICENSE=	APACHE20

RUN_DEPENDS=	jsvc:devel/apache-commons-daemon

USES=		cpe java
CPE_VENDOR=	apache
JAVA_VERSION=	17+
USE_RC_SUBR=	${PKGBASE:C/-/_/}

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/apache-${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
PLIST_SUB=	T=${TOMEE_PLUS_SUBDIR} \
		WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}
SUB_LIST=	TOMEE_PLUS_HOME=${TOMEE_PLUS_HOME} \
		TOMEE_PLUS_USER=${WWWOWN} \
		JAVA_HOME=${JAVA_HOME}

OPTIONS_DEFINE=		HOST_MANAGER MANAGER DOCS ROOT NLS
OPTIONS_DEFAULT=	HOST_MANAGER MANAGER ROOT
OPTIONS_SUB=		yes

DOCS_DESC=		Install Documentation web application
HOST_MANAGER_DESC=	Install Host Manager application
MANAGER_DESC=		Install Manager web application
ROOT_DESC=		Install default ROOT web application

TOMEE_PLUS_SUBDIR?=	apache-${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION:R}
TOMEE_PLUS_HOME=	${PREFIX}/${TOMEE_PLUS_SUBDIR}

post-patch:
	@${RM} ${WRKSRC}/bin/commons-daemon-native.tar.gz ${WRKSRC}/bin/commons-daemon.jar ${WRKSRC}/bin/tomcat-native.tar.gz
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g; s|%%JAVAJARDIR%%|${JAVAJARDIR}|g' ${WRKSRC}/bin/daemon.sh
	@${FIND} ${WRKSRC} -name '*.bat' -delete -o -name '*.bat.original' -delete -o -name '*.exe' -delete

do-install:
	@${MKDIR} ${STAGEDIR}${TOMEE_PLUS_HOME}/logs
	@${MKDIR} ${STAGEDIR}${TOMEE_PLUS_HOME}/endorsed
	@${CP} -R ${WRKSRC}/* ${STAGEDIR}${TOMEE_PLUS_HOME}

post-install:
	@(cd ${STAGEDIR}${TOMEE_PLUS_HOME}/conf &&\
		for f in $$(find . -type f -not -name '*.xsd' -a -not -name '*.original'); do ${MV} $$f $$f.sample; done)

post-install-HOST_MANAGER-on:
	@(cd ${STAGEDIR}${TOMEE_PLUS_HOME}/webapps &&\
		for f in host-manager/META-INF/context.xml host-manager/WEB-INF/manager.xml host-manager/WEB-INF/web.xml; do \
			${MV} $$f $$f.sample; done)

post-install-MANAGER-on:
	@(cd ${STAGEDIR}${TOMEE_PLUS_HOME}/webapps &&\
		for f in manager/META-INF/context.xml manager/WEB-INF/web.xml; do \
			${MV} $$f $$f.sample; done)

.include <bsd.port.mk>

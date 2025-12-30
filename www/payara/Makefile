PORTNAME=	payara
DISTVERSION=	7.2025.2
CATEGORIES=	www java
MASTER_SITES=	https://repo1.maven.org/maven2/fish/payara/distributions/${PORTNAME}/${DISTVERSION}/
MAINTAINER=	dmytro@posteo.net
COMMENT=	Jakarta EE application server derived from GlassFish Server Open Source Edition
WWW=		https://www.payara.fish/

LICENSE=	GPLv2 CDDL
LICENSE_COMB=	dual

USES=		java zip

JAVA_VERSION=   21+

NO_ARCH=        yes
NO_BUILD=	yes

SUB_FILES=      pkg-message

WRKSRC=         ${WRKDIR}/${PORTNAME}7
DATADIR=	${PREFIX}/${PORTNAME}-${DISTVERSION}
VARMAIN=	/var/${PORTNAME}
VARDIR=		/var/${PORTNAME}/${PORTNAME}-${DISTVERSION}

PLIST_SUB+=	VARDIR=${VARDIR}
PLIST_SUB+=	VARMAIN=${VARMAIN}

# Since we USES=java, we propagate the received JAVA_HOME variable to the
# template files, since it is used by the rc script.
SUB_LIST=	PAYARAVERSION=${DISTVERSION} \
		JAVA_HOME=${JAVA_HOME} \
		VARDIR=${VARDIR}

USE_RC_SUBR=    ${PORTNAME}

USERS=          ${PORTNAME}
GROUPS=         ${PORTNAME}

EXTRACT_BEFORE_ARGS=    -qo -x '*.bat' -x '*.exe' -x '*.dll' \
                        -x '*/bin/letsencrypt.py'

do-install:
	@${MKDIR} ${STAGEDIR}${VARDIR}/prefs
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@${FIND} ${STAGEDIR}${DATADIR}/glassfish/domains -path "*/config/*" -type f -exec ${MV} {} {}.sample \;
	@${MV} ${STAGEDIR}${DATADIR}/glassfish/domains ${STAGEDIR}${VARDIR}/domains
	@${RLN} ${STAGEDIR}${VARDIR}/domains ${STAGEDIR}${DATADIR}/glassfish/domains
	@${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/bin/* \
                  ${STAGEDIR}${DATADIR}/mq/bin/* \
                  ${STAGEDIR}${DATADIR}/glassfish/bin/*

.include <bsd.port.mk>

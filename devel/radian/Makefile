PORTNAME=	radian
DISTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	devel math python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	21st century R console
WWW=		https://github.com/randy3k/radian

LICENSE=	MIT

DEPRECATED=	Depends on expired devel/py-pytest-runner
EXPIRATION_DATE=2025-03-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lineedit>=0.1.4,<0.2.0:devel/py-lineedit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.5.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rchitect>=0.3.17,<0.4.0:devel/py-rchitect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

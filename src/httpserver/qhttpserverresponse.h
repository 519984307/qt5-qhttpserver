/****************************************************************************
**
** Copyright (C) 2018 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtHttpServer module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QHTTPSERVERRESPONSE_H
#define QHTTPSERVERRESPONSE_H

#include <QtHttpServer/qhttpserverresponder.h>

#include <QtCore/qscopedpointer.h>

QT_BEGIN_NAMESPACE

class QJsonObject;

class QHttpServerResponsePrivate;
class Q_HTTPSERVER_EXPORT QHttpServerResponse
{
    Q_DECLARE_PRIVATE(QHttpServerResponse)

public:
    using StatusCode = QHttpServerResponder::StatusCode;

    QHttpServerResponse() = delete;
    QHttpServerResponse(const QHttpServerResponse &other) = delete;
    QHttpServerResponse& operator=(const QHttpServerResponse &other) = delete;

    QHttpServerResponse(QHttpServerResponse &&other);
    QHttpServerResponse& operator=(QHttpServerResponse &&other) = delete;

    QHttpServerResponse(const StatusCode statusCode);
    QHttpServerResponse(const char *data);
    QHttpServerResponse(const QString &data);
    explicit QHttpServerResponse(const QByteArray &data);
    QHttpServerResponse(const QJsonObject &data);
    QHttpServerResponse(const QByteArray &mimeType,
                        const QByteArray &data,
                        const StatusCode status = StatusCode::Ok);
    virtual ~QHttpServerResponse();

    QByteArray data() const;

    QByteArray mimeType() const;

    StatusCode statusCode() const;
private:
    QHttpServerResponse(QHttpServerResponsePrivate *d);

    QScopedPointer<QHttpServerResponsePrivate> d_ptr;
};

QT_END_NAMESPACE

#endif   // QHTTPSERVERRESPONSE_H
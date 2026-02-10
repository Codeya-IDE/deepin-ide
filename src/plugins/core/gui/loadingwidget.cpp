// SPDX-FileCopyrightText: 2023 - 2025 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "loadingwidget.h"

#include <QVBoxLayout>

DWIDGET_USE_NAMESPACE

loadingWidget::loadingWidget(QWidget *parent)
    : DWidget(parent)
{
    QVBoxLayout *vlayout = new QVBoxLayout(this);

    setLogo();

    loadingText = new DLabel(this);
    loadingText->setText(tr("loading..."));
    loadingText->setAlignment(Qt::AlignCenter);

    vlayout->addWidget(logo);
    vlayout->addWidget(loadingText);
    vlayout->setAlignment(Qt::AlignCenter);
}

void loadingWidget::setLogo()
{
    logo = new DLabel(this);
    logo->setPixmap(QIcon::fromTheme("ide").pixmap(128));
    logo->setAlignment(Qt::AlignCenter);

    opacityEffect = new QGraphicsOpacityEffect(logo);
    logo->setGraphicsEffect(opacityEffect);

    connect(&timer, &QTimer::timeout, this, [this]() {
        // 透明度在 0.3 到 1.0 之间循环变化，产生呼吸效果
        if (fadeOut) {
            logoOpacity -= 0.05;
            if (logoOpacity <= 0.3) {
                logoOpacity = 0.3;
                fadeOut = false;
            }
        } else {
            logoOpacity += 0.05;
            if (logoOpacity >= 1.0) {
                logoOpacity = 1.0;
                fadeOut = true;
            }
        }
        opacityEffect->setOpacity(logoOpacity);
    });
    timer.start(50);
}

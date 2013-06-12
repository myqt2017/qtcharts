/****************************************************************************
**
** Copyright (C) 2013 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Enterprise Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Enterprise licenses may use this file in
** accordance with the Qt Enterprise License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QBARSET_H
#define QBARSET_H

#include <qchartglobal.h>
#include <QPen>
#include <QBrush>
#include <QFont>

QTCOMMERCIALCHART_BEGIN_NAMESPACE
class QBarSetPrivate;

class QTCOMMERCIALCHART_EXPORT QBarSet : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)
    Q_PROPERTY(QPen pen READ pen WRITE setPen NOTIFY penChanged)
    Q_PROPERTY(QBrush brush READ brush WRITE setBrush NOTIFY brushChanged)
    Q_PROPERTY(QBrush labelBrush READ labelBrush WRITE setLabelBrush NOTIFY labelBrushChanged)
    Q_PROPERTY(QFont labelFont READ labelFont WRITE setLabelFont NOTIFY labelFontChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor NOTIFY borderColorChanged)
    Q_PROPERTY(QColor labelColor READ labelColor WRITE setLabelColor NOTIFY labelColorChanged)

public:
    explicit QBarSet(const QString label, QObject *parent = 0);
    virtual ~QBarSet();

    void setLabel(const QString label);
    QString label() const;

    void append(const qreal value);
    void append(const QList<qreal> &values);

    QBarSet &operator << (const qreal &value);

    void insert(const int index, const qreal value);
    void remove(const int index, const int count = 1);
    void replace(const int index, const qreal value);
    qreal at(const int index) const;
    qreal operator [](const int index) const;
    int count() const;
    qreal sum() const;

    void setPen(const QPen &pen);
    QPen pen() const;

    void setBrush(const QBrush &brush);
    QBrush brush() const;

    void setLabelBrush(const QBrush &brush);
    QBrush labelBrush() const;

    void setLabelFont(const QFont &font);
    QFont labelFont() const;

    QColor color();
    void setColor(QColor color);

    QColor borderColor();
    void setBorderColor(QColor color);

    QColor labelColor();
    void setLabelColor(QColor color);

Q_SIGNALS:
    void clicked(int index);
    void hovered(bool status);
    void penChanged();
    void brushChanged();
    void labelChanged();
    void labelBrushChanged();
    void labelFontChanged();
    void colorChanged(QColor color);
    void borderColorChanged(QColor color);
    void labelColorChanged(QColor color);

    void valuesAdded(int index, int count);
    void valuesRemoved(int index, int count);
    void valueChanged(int index);

private:
    QScopedPointer<QBarSetPrivate> d_ptr;
    Q_DISABLE_COPY(QBarSet)
    friend class QAbstractBarSeries;
    friend class BarLegendMarker;
    friend class AbstractBarChartItem;
    friend class QAbstractBarSeriesPrivate;
    friend class StackedBarChartItem;
    friend class PercentBarChartItem;
    friend class BarChartItem;
    friend class HorizontalBarChartItem;
    friend class HorizontalStackedBarChartItem;
    friend class HorizontalPercentBarChartItem;
    friend class BoxPlotChartItem;
};

QTCOMMERCIALCHART_END_NAMESPACE

#endif // QBARSET_H

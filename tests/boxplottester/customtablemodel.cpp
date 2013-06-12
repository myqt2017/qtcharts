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

#include "customtablemodel.h"
#include <QVector>
#include <QTime>
#include <QRect>
#include <QColor>

const QString categories[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Nov", "Dec"};

CustomTableModel::CustomTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    m_columnCount = 6;
    m_rowCount = 5;
    QVector<qreal>* dataVec_Jan = new QVector<qreal>(m_rowCount);
    dataVec_Jan->insert(0, 3.0);
    dataVec_Jan->insert(1, 4.0);
    dataVec_Jan->insert(2, 4.4);
    dataVec_Jan->insert(3, 6.0);
    dataVec_Jan->insert(4, 7.0);
    m_data.append(dataVec_Jan);

    QVector<qreal>* dataVec_Feb = new QVector<qreal>(m_rowCount);
    dataVec_Feb->insert(0, 5.0);
    dataVec_Feb->insert(1, 6.0);
    dataVec_Feb->insert(2, 7.5);
    dataVec_Feb->insert(3, 8.0);
    dataVec_Feb->insert(4, 12.0);
    m_data.append(dataVec_Feb);

    QVector<qreal>* dataVec_Mar = new QVector<qreal>(m_rowCount);
    dataVec_Mar->insert(0, 3.0);
    dataVec_Mar->insert(1, 4.0);
    dataVec_Mar->insert(2, 5.7);
    dataVec_Mar->insert(3, 8.0);
    dataVec_Mar->insert(4, 9.0);
    m_data.append(dataVec_Mar);

    QVector<qreal>* dataVec_Apr = new QVector<qreal>(m_rowCount);
    dataVec_Apr->insert(0, 5.0);
    dataVec_Apr->insert(1, 6.0);
    dataVec_Apr->insert(2, 6.8);
    dataVec_Apr->insert(3, 7.0);
    dataVec_Apr->insert(4, 8.0);
    m_data.append(dataVec_Apr);

    QVector<qreal>* dataVec_May = new QVector<qreal>(m_rowCount);
    dataVec_May->insert(0, 4.0);
    dataVec_May->insert(1, 5.0);
    dataVec_May->insert(2, 5.2);
    dataVec_May->insert(3, 6.0);
    dataVec_May->insert(4, 7.0);
    m_data.append(dataVec_May);

    QVector<qreal>* dataVec_Jun = new QVector<qreal>(m_rowCount);
    dataVec_Jun->insert(0, 4.0);
    dataVec_Jun->insert(1, 7.0);
    dataVec_Jun->insert(2, 8.2);
    dataVec_Jun->insert(3, 9.0);
    dataVec_Jun->insert(4, 10.0);
    m_data.append(dataVec_Jun);
}

int CustomTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_rowCount;
}

int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.count();
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return categories[section];
    else
        return QString("%1").arg(section + 1);
}

QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return m_data[index.column()]->at(index.row());
    } else if (role == Qt::EditRole) {
        return m_data[index.column()]->at(index.row());
    } else if (role == Qt::BackgroundRole) {
        QRect rect;
        foreach (rect, m_mapping)
        if (rect.contains(index.column(), index.row()))
            return QColor(m_mapping.key(rect));

        // cell not mapped return white color
        return QColor(Qt::white);
    }
    return QVariant();
}

bool CustomTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        m_data[index.column()]->replace(index.row(), value.toDouble());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags CustomTableModel::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void CustomTableModel::addMapping(QString color, QRect area)
{
    m_mapping.insertMulti(color, area);
}

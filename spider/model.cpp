#include "model.h"

Model::Model(int r, int c, QVector<QString>& head, QVector<QStringList>& dt, QObject *parent)
    : QAbstractItemModel(parent)
    , row{r}
    , col{c}
    , headData{std::move(head)}
    , dataModel{std::move(dt)}
{}

void Model::insertRow(const QStringList dt)
{
    this->dataModel.push_back(dt);
    emit layoutChanged();
}

QModelIndex Model::index(int row, int column, const QModelIndex&) const
{
    return createIndex(row, column);
}

QModelIndex Model::parent(const QModelIndex&) const
{
    return QModelIndex();
}

int Model::rowCount(const QModelIndex&) const
{
    return this->row;
}

int Model::columnCount(const QModelIndex&) const
{
    return this->col;
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    switch (role) {
        case Qt::DisplayRole:
            return this->dataModel[index.row()][index.column()];

        case Qt::TextAlignmentRole:
            return Qt::AlignCenter;

        case Qt::BackgroundRole:
            return QBrush(QColor(100, 100, 100, 50));
    }
    return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();

    return orientation == Qt::Horizontal ? this->headData[section] : QVariant();
}







#ifndef MODEL_H
#define MODEL_H


#include <QAbstractItemModel>
#include <QBrush>
#include <QFont>

class Model : public QAbstractItemModel
{
public:
    Model(int r, int c, QVector<QString>& head, QVector<QStringList>& dt, QObject *parent=0);

    void insertRow(const QStringList dt);

    // QAbstractItemModel interface
public:
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:

    int                     row;
    int                     col;
    QVector<QString>        headData;
    QVector<QStringList>    dataModel;
};

#endif // MODEL_H

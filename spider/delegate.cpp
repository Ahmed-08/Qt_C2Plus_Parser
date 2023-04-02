#include "delegate.h"

Delegate::Delegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(option.state & QStyle::State_MouseOver)
    {
        painter->fillRect(option.rect, QBrush(QColor(255, 110, 160, 50)));
    }
    QStyledItemDelegate::paint(painter, option, index);
}

QSize Delegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(!index.isValid())
        return QSize();

    return QSize(option.rect.width(), 55);
}

#ifndef FILTERS_H
#define FILTERS_H

#include <QDialog>
#include <QStringList>

#include "StructEnumDefinition_CopyEngine.h"

namespace Ui {
class Filters;
}

class Filters : public QDialog
{
	Q_OBJECT
public:
	struct Filters_rules
	{
		QString search_text;
		SearchType search_type;
		ApplyOn apply_on;
		bool need_match_all;
	};
	explicit Filters(QWidget *parent = 0);
	~Filters();
	void setFilters(QStringList includeStrings,QStringList includeOptions,QStringList excludeStrings,QStringList excludeOptions);
	void reShowAll();
	QList<Filters_rules> getInclude();
	QList<Filters_rules> getExclude();
private:
	Ui::Filters *ui;
	QList<Filters_rules> include;
	QList<Filters_rules> exclude;
	void changeEvent(QEvent *e);
	void haveNewFilters();
signals:
	void sendNewFilters(QStringList includeStrings,QStringList includeOptions,QStringList excludeStrings,QStringList excludeOptions);
private slots:
	void on_remove_exclusion_clicked();
	void on_remove_inclusion_clicked();
};

#endif // FILTERS_H

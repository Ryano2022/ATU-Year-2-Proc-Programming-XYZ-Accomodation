#ifndef DATABASE_H
#define DATABASE_H

void accommodationAdd(int editMode);
void accommodationDisplay(int version, int saveMode);
void accommodationEdit();
void accommodationDelete();
void accommodationGenStatistics(int saveMode);
void accommodationSaveToFile();
void accommodationSortByMonthly();

#endif

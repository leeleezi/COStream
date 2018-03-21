//��ȡSDF��actor����Ϣ�����ͼ���С
#ifndef _ACTOREDGEINFO_H_
#define _ACTOREDGEINFO_H_
#include "flatNode.h"
#include "Partition.h"
#include <set>

using namespace std;
struct StreamEdgeInfo	
{
	string typedefine;
	int size;//��С
	string typeName;//��������
	StreamEdgeInfo(int size,string typeName,string typedefine):size(size),typeName(typeName),typedefine(typedefine){}
	StreamEdgeInfo(){}
};

class ActorEdgeInfo
{
public:
	ActorEdgeInfo(SchedulerSSG*);
	
	ActorEdgeInfo(DividedStaticGraph*);
	StreamEdgeInfo getEdgeInfo(FlatNode*,FlatNode*);
	void DeclEdgeType(stringstream &buf);

private:	
	vector<FlatNode *> flatNodes_;
	map<pair<FlatNode*,FlatNode*>,StreamEdgeInfo> mapEdge2TypeInfo;//�洢ÿ���ߵ���������Ϣ��ӳ��
	vector<StreamEdgeInfo> vStreamTypeInfo;	//��Ÿ������ͱߵ���Ϣ
	
};
//��Ϊ��������
extern string GetPrimDataType(Node *from, int *);
extern string GetPrimDataType(Node *from);
extern string GetArrayDataType(Node *node);
extern string GetArrayDim(Node *node);
#endif
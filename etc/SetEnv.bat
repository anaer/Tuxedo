rem ���õ������⻷������THIRD_PARTY

wmic ENVIRONMENT where "name='TUXCONFIG'" delete
wmic ENVIRONMENT create name="TUXCONFIG",username="<system>",VariableValue="E:\code\Tuxedo\etc\tuxconfig"


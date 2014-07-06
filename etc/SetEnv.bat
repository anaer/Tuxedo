rem 设置第三方库环境变量THIRD_PARTY

wmic ENVIRONMENT where "name='TUXCONFIG'" delete
wmic ENVIRONMENT create name="TUXCONFIG",username="<system>",VariableValue="E:\anaer\Tuxedo\etc\tuxconfig"


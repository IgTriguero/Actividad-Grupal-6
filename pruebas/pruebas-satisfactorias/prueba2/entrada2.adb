procedure Secondary is
   variableint1 : Integer;
   variablefloat1 : Float;
begin
   variableint1:= 2 + 10 ;
   variablefloat1 := 2.9;
   if variablefloat1 > 3.0 then
     variableint1 := variableint1 * 2;
   else
      variablefloat1 := variableint1 / 2;
   end if;
end Secondary ;
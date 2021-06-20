procedure Main is

   variable_string1 : String := "String 1";
   variable_int1 : Integer := 2 + 10 ;
   variable_int2 : Integer := 3 + 7 ;
   variable_float1 : Float := 1.8;
   variable_bool : Boolean :=  2.9 == variable_float1 ;


   if variable_float1 > 0.0 and variable_bool then
     variable_int1 := variable_int1 * 2;
     else
      variable_int1 := variable_int2 / 2;
   end if;
end Main ;
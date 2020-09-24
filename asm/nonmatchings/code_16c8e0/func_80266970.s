.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80266970
/* 195250 80266970 03E00008 */  jr        $ra
/* 195254 80266974 A0800204 */   sb       $zero, 0x204($a0)

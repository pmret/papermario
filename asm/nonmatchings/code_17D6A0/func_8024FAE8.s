.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024FAE8
/* 17E3C8 8024FAE8 24020001 */  addiu     $v0, $zero, 1
/* 17E3CC 8024FAEC 3C01802A */  lui       $at, 0x802a
/* 17E3D0 8024FAF0 A422F64C */  sh        $v0, -0x9b4($at)
/* 17E3D4 8024FAF4 03E00008 */  jr        $ra
/* 17E3D8 8024FAF8 00000000 */   nop      

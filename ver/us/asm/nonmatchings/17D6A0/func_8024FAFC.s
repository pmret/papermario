.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024FAFC
/* 17E3DC 8024FAFC 3C01802A */  lui       $at, %hi(D_8029F64C)
/* 17E3E0 8024FB00 A420F64C */  sh        $zero, %lo(D_8029F64C)($at)
/* 17E3E4 8024FB04 03E00008 */  jr        $ra
/* 17E3E8 8024FB08 00000000 */   nop

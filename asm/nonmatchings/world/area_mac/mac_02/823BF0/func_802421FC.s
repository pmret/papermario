.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421FC
/* 8254BC 802421FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8254C0 80242200 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8254C4 80242204 8C82000C */  lw        $v0, 0xc($a0)
/* 8254C8 80242208 0C0B1EAF */  jal       get_variable
/* 8254CC 8024220C 8C450000 */   lw       $a1, ($v0)
/* 8254D0 80242210 3C038025 */  lui       $v1, 0x8025
/* 8254D4 80242214 8C63E560 */  lw        $v1, -0x1aa0($v1)
/* 8254D8 80242218 8C63000C */  lw        $v1, 0xc($v1)
/* 8254DC 8024221C AC620034 */  sw        $v0, 0x34($v1)
/* 8254E0 80242220 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8254E4 80242224 24020002 */  addiu     $v0, $zero, 2
/* 8254E8 80242228 03E00008 */  jr        $ra
/* 8254EC 8024222C 27BD0018 */   addiu    $sp, $sp, 0x18

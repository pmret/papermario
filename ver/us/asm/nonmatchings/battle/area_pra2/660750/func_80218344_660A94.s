.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218344_660A94
/* 660A94 80218344 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 660A98 80218348 AFBF0010 */  sw        $ra, 0x10($sp)
/* 660A9C 8021834C 8C82000C */  lw        $v0, 0xc($a0)
/* 660AA0 80218350 0C0B1EAF */  jal       get_variable
/* 660AA4 80218354 8C450000 */   lw       $a1, ($v0)
/* 660AA8 80218358 8C43000C */  lw        $v1, 0xc($v0)
/* 660AAC 8021835C 240500FF */  addiu     $a1, $zero, 0xff
/* 660AB0 80218360 AC650018 */  sw        $a1, 0x18($v1)
/* 660AB4 80218364 8C43000C */  lw        $v1, 0xc($v0)
/* 660AB8 80218368 AC65001C */  sw        $a1, 0x1c($v1)
/* 660ABC 8021836C 8C43000C */  lw        $v1, 0xc($v0)
/* 660AC0 80218370 AC650020 */  sw        $a1, 0x20($v1)
/* 660AC4 80218374 8C44000C */  lw        $a0, 0xc($v0)
/* 660AC8 80218378 240300C8 */  addiu     $v1, $zero, 0xc8
/* 660ACC 8021837C AC830028 */  sw        $v1, 0x28($a0)
/* 660AD0 80218380 8C44000C */  lw        $a0, 0xc($v0)
/* 660AD4 80218384 240300F0 */  addiu     $v1, $zero, 0xf0
/* 660AD8 80218388 AC83002C */  sw        $v1, 0x2c($a0)
/* 660ADC 8021838C 8C43000C */  lw        $v1, 0xc($v0)
/* 660AE0 80218390 AC650030 */  sw        $a1, 0x30($v1)
/* 660AE4 80218394 8FBF0010 */  lw        $ra, 0x10($sp)
/* 660AE8 80218398 24020002 */  addiu     $v0, $zero, 2
/* 660AEC 8021839C 03E00008 */  jr        $ra
/* 660AF0 802183A0 27BD0018 */   addiu    $sp, $sp, 0x18

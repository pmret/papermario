.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219658_465AE8
/* 465AE8 80219658 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 465AEC 8021965C AFB00010 */  sw        $s0, 0x10($sp)
/* 465AF0 80219660 0080802D */  daddu     $s0, $a0, $zero
/* 465AF4 80219664 AFBF0018 */  sw        $ra, 0x18($sp)
/* 465AF8 80219668 AFB10014 */  sw        $s1, 0x14($sp)
/* 465AFC 8021966C 8E040148 */  lw        $a0, 0x148($s0)
/* 465B00 80219670 0C09A75B */  jal       get_actor
/* 465B04 80219674 8E11000C */   lw       $s1, 0xc($s0)
/* 465B08 80219678 0200202D */  daddu     $a0, $s0, $zero
/* 465B0C 8021967C 8E250000 */  lw        $a1, ($s1)
/* 465B10 80219680 0C0B1EAF */  jal       evt_get_variable
/* 465B14 80219684 8C500094 */   lw       $s0, 0x94($v0)
/* 465B18 80219688 AE020004 */  sw        $v0, 4($s0)
/* 465B1C 8021968C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 465B20 80219690 8FB10014 */  lw        $s1, 0x14($sp)
/* 465B24 80219694 8FB00010 */  lw        $s0, 0x10($sp)
/* 465B28 80219698 24020002 */  addiu     $v0, $zero, 2
/* 465B2C 8021969C 03E00008 */  jr        $ra
/* 465B30 802196A0 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800448EC
/* 1FCEC 800448EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1FCF0 800448F0 AFB20018 */  sw        $s2, 0x18($sp)
/* 1FCF4 800448F4 0080902D */  daddu     $s2, $a0, $zero
/* 1FCF8 800448F8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1FCFC 800448FC AFB10014 */  sw        $s1, 0x14($sp)
/* 1FD00 80044900 AFB00010 */  sw        $s0, 0x10($sp)
/* 1FD04 80044904 8E42000C */  lw        $v0, 0xc($s2)
/* 1FD08 80044908 8C450000 */  lw        $a1, ($v0)
/* 1FD0C 8004490C 0C0B1EAF */  jal       func_802C7ABC
/* 1FD10 80044910 8E500148 */   lw       $s0, 0x148($s2)
/* 1FD14 80044914 0040202D */  daddu     $a0, $v0, $zero
/* 1FD18 80044918 2402FFFF */  addiu     $v0, $zero, -1
/* 1FD1C 8004491C 14820002 */  bne       $a0, $v0, .L80044928
/* 1FD20 80044920 00000000 */   nop
/* 1FD24 80044924 86040008 */  lh        $a0, 8($s0)
.L80044928:
/* 1FD28 80044928 0C00FA6A */  jal       func_8003E9A8
/* 1FD2C 8004492C 2411000B */   addiu    $s1, $zero, 0xb
/* 1FD30 80044930 0040802D */  daddu     $s0, $v0, $zero
/* 1FD34 80044934 8E020000 */  lw        $v0, ($s0)
/* 1FD38 80044938 30420001 */  andi      $v0, $v0, 1
/* 1FD3C 8004493C 54400001 */  bnel      $v0, $zero, .L80044944
/* 1FD40 80044940 2411000A */   addiu    $s1, $zero, 0xa
.L80044944:
/* 1FD44 80044944 8E02003C */  lw        $v0, 0x3c($s0)
/* 1FD48 80044948 10400005 */  beqz      $v0, .L80044960
/* 1FD4C 8004494C 2405000A */   addiu    $a1, $zero, 0xa
/* 1FD50 80044950 8E040054 */  lw        $a0, 0x54($s0)
/* 1FD54 80044954 0C0B102B */  jal       func_802C40AC
/* 1FD58 80044958 90510004 */   lbu      $s1, 4($v0)
/* 1FD5C 8004495C 2405000A */  addiu     $a1, $zero, 0xa
.L80044960:
/* 1FD60 80044960 24020064 */  addiu     $v0, $zero, 0x64
/* 1FD64 80044964 8E040024 */  lw        $a0, 0x24($s0)
/* 1FD68 80044968 0000302D */  daddu     $a2, $zero, $zero
/* 1FD6C 8004496C 0C0B0CF8 */  jal       func_802C33E0
/* 1FD70 80044970 AE0200C8 */   sw       $v0, 0xc8($s0)
/* 1FD74 80044974 0040182D */  daddu     $v1, $v0, $zero
/* 1FD78 80044978 AE03003C */  sw        $v1, 0x3c($s0)
/* 1FD7C 8004497C 8C620144 */  lw        $v0, 0x144($v1)
/* 1FD80 80044980 AE020054 */  sw        $v0, 0x54($s0)
/* 1FD84 80044984 AC700148 */  sw        $s0, 0x148($v1)
/* 1FD88 80044988 8E44014C */  lw        $a0, 0x14c($s2)
/* 1FD8C 8004498C A0710004 */  sb        $s1, 4($v1)
/* 1FD90 80044990 AC64014C */  sw        $a0, 0x14c($v1)
/* 1FD94 80044994 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1FD98 80044998 8FB20018 */  lw        $s2, 0x18($sp)
/* 1FD9C 8004499C 8FB10014 */  lw        $s1, 0x14($sp)
/* 1FDA0 800449A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 1FDA4 800449A4 24020002 */  addiu     $v0, $zero, 2
/* 1FDA8 800449A8 03E00008 */  jr        $ra
/* 1FDAC 800449AC 27BD0020 */   addiu    $sp, $sp, 0x20

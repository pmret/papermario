.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80065C90
/* 41090 80065C90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 41094 80065C94 3C02A480 */  lui       $v0, 0xa480
/* 41098 80065C98 34420018 */  ori       $v0, $v0, 0x18
/* 4109C 80065C9C AFBF0018 */  sw        $ra, 0x18($sp)
/* 410A0 80065CA0 AFB10014 */  sw        $s1, 0x14($sp)
/* 410A4 80065CA4 AFB00010 */  sw        $s0, 0x10($sp)
/* 410A8 80065CA8 8C420000 */  lw        $v0, ($v0)
/* 410AC 80065CAC 00808021 */  addu      $s0, $a0, $zero
/* 410B0 80065CB0 30420003 */  andi      $v0, $v0, 3
/* 410B4 80065CB4 10400003 */  beqz      $v0, .L80065CC4
/* 410B8 80065CB8 00A08821 */   addu     $s1, $a1, $zero
/* 410BC 80065CBC 08019748 */  j         .L80065D20
/* 410C0 80065CC0 2402FFFF */   addiu    $v0, $zero, -1
.L80065CC4:
/* 410C4 80065CC4 24020001 */  addiu     $v0, $zero, 1
/* 410C8 80065CC8 16020003 */  bne       $s0, $v0, .L80065CD8
/* 410CC 80065CCC 02202021 */   addu     $a0, $s1, $zero
/* 410D0 80065CD0 0C018608 */  jal       func_80061820
/* 410D4 80065CD4 24050040 */   addiu    $a1, $zero, 0x40
.L80065CD8:
/* 410D8 80065CD8 0C018798 */  jal       func_80061E60
/* 410DC 80065CDC 02202021 */   addu     $a0, $s1, $zero
/* 410E0 80065CE0 3C03A480 */  lui       $v1, 0xa480
/* 410E4 80065CE4 AC620000 */  sw        $v0, ($v1)
/* 410E8 80065CE8 56000003 */  bnel      $s0, $zero, .L80065CF8
/* 410EC 80065CEC 3C03A480 */   lui      $v1, 0xa480
/* 410F0 80065CF0 0801973F */  j         .L80065CFC
/* 410F4 80065CF4 34630004 */   ori      $v1, $v1, 4
.L80065CF8:
/* 410F8 80065CF8 34630010 */  ori       $v1, $v1, 0x10
.L80065CFC:
/* 410FC 80065CFC 3C021FC0 */  lui       $v0, 0x1fc0
/* 41100 80065D00 344207C0 */  ori       $v0, $v0, 0x7c0
/* 41104 80065D04 AC620000 */  sw        $v0, ($v1)
/* 41108 80065D08 16000005 */  bnez      $s0, .L80065D20
/* 4110C 80065D0C 00001021 */   addu     $v0, $zero, $zero
/* 41110 80065D10 02202021 */  addu      $a0, $s1, $zero
/* 41114 80065D14 0C0185BC */  jal       func_800616F0
/* 41118 80065D18 24050040 */   addiu    $a1, $zero, 0x40
/* 4111C 80065D1C 00001021 */  addu      $v0, $zero, $zero
.L80065D20:
/* 41120 80065D20 8FBF0018 */  lw        $ra, 0x18($sp)
/* 41124 80065D24 8FB10014 */  lw        $s1, 0x14($sp)
/* 41128 80065D28 8FB00010 */  lw        $s0, 0x10($sp)
/* 4112C 80065D2C 03E00008 */  jr        $ra
/* 41130 80065D30 27BD0020 */   addiu    $sp, $sp, 0x20
/* 41134 80065D34 00000000 */  nop
/* 41138 80065D38 00000000 */  nop
/* 4113C 80065D3C 00000000 */  nop

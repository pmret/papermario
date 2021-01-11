.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osSiRawStartDma
/* 410C0 80065CC0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 410C4 80065CC4 3C02A480 */  lui       $v0, 0xa480
/* 410C8 80065CC8 34420018 */  ori       $v0, $v0, 0x18
/* 410CC 80065CCC AFBF0018 */  sw        $ra, 0x18($sp)
/* 410D0 80065CD0 AFB10014 */  sw        $s1, 0x14($sp)
/* 410D4 80065CD4 AFB00010 */  sw        $s0, 0x10($sp)
/* 410D8 80065CD8 8C420000 */  lw        $v0, ($v0)
/* 410DC 80065CDC 00808021 */  addu      $s0, $a0, $zero
/* 410E0 80065CE0 30420003 */  andi      $v0, $v0, 3
/* 410E4 80065CE4 10400003 */  beqz      $v0, .L80065CF4
/* 410E8 80065CE8 00A08821 */   addu     $s1, $a1, $zero
/* 410EC 80065CEC 08019754 */  j         .L80065D50
/* 410F0 80065CF0 2402FFFF */   addiu    $v0, $zero, -1
.L80065CF4:
/* 410F4 80065CF4 24020001 */  addiu     $v0, $zero, 1
/* 410F8 80065CF8 16020003 */  bne       $s0, $v0, .L80065D08
/* 410FC 80065CFC 02202021 */   addu     $a0, $s1, $zero
/* 41100 80065D00 0C018614 */  jal       osWritebackDCache
/* 41104 80065D04 24050040 */   addiu    $a1, $zero, 0x40
.L80065D08:
/* 41108 80065D08 0C0187A4 */  jal       osVirtualToPhysical
/* 4110C 80065D0C 02202021 */   addu     $a0, $s1, $zero
/* 41110 80065D10 3C03A480 */  lui       $v1, 0xa480
/* 41114 80065D14 AC620000 */  sw        $v0, ($v1)
/* 41118 80065D18 56000003 */  bnel      $s0, $zero, .L80065D28
/* 4111C 80065D1C 3C03A480 */   lui      $v1, 0xa480
/* 41120 80065D20 0801974B */  j         .L80065D2C
/* 41124 80065D24 34630004 */   ori      $v1, $v1, 4
.L80065D28:
/* 41128 80065D28 34630010 */  ori       $v1, $v1, 0x10
.L80065D2C:
/* 4112C 80065D2C 3C021FC0 */  lui       $v0, 0x1fc0
/* 41130 80065D30 344207C0 */  ori       $v0, $v0, 0x7c0
/* 41134 80065D34 AC620000 */  sw        $v0, ($v1)
/* 41138 80065D38 16000005 */  bnez      $s0, .L80065D50
/* 4113C 80065D3C 00001021 */   addu     $v0, $zero, $zero
/* 41140 80065D40 02202021 */  addu      $a0, $s1, $zero
/* 41144 80065D44 0C0185C8 */  jal       osInvalDCache
/* 41148 80065D48 24050040 */   addiu    $a1, $zero, 0x40
/* 4114C 80065D4C 00001021 */  addu      $v0, $zero, $zero
.L80065D50:
/* 41150 80065D50 8FBF0018 */  lw        $ra, 0x18($sp)
/* 41154 80065D54 8FB10014 */  lw        $s1, 0x14($sp)
/* 41158 80065D58 8FB00010 */  lw        $s0, 0x10($sp)
/* 4115C 80065D5C 03E00008 */  jr        $ra
/* 41160 80065D60 27BD0020 */   addiu    $sp, $sp, 0x20
/* 41164 80065D64 00000000 */  nop
/* 41168 80065D68 00000000 */  nop
/* 4116C 80065D6C 00000000 */  nop

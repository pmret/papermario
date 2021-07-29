.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802EB270
.double 0.01

.section .text

glabel entity_HeartBlockContent_anim_idle
/* 106490 802E4C10 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 106494 802E4C14 AFB10024 */  sw        $s1, 0x24($sp)
/* 106498 802E4C18 0080882D */  daddu     $s1, $a0, $zero
/* 10649C 802E4C1C AFBF0028 */  sw        $ra, 0x28($sp)
/* 1064A0 802E4C20 AFB00020 */  sw        $s0, 0x20($sp)
/* 1064A4 802E4C24 8E300040 */  lw        $s0, 0x40($s1)
/* 1064A8 802E4C28 92030001 */  lbu       $v1, 1($s0)
/* 1064AC 802E4C2C 24020001 */  addiu     $v0, $zero, 1
/* 1064B0 802E4C30 10620014 */  beq       $v1, $v0, .L802E4C84
/* 1064B4 802E4C34 28620002 */   slti     $v0, $v1, 2
/* 1064B8 802E4C38 10400005 */  beqz      $v0, .L802E4C50
/* 1064BC 802E4C3C 24020002 */   addiu    $v0, $zero, 2
/* 1064C0 802E4C40 50600009 */  beql      $v1, $zero, .L802E4C68
/* 1064C4 802E4C44 AE200054 */   sw       $zero, 0x54($s1)
/* 1064C8 802E4C48 080B935C */  j         .L802E4D70
/* 1064CC 802E4C4C 00000000 */   nop
.L802E4C50:
/* 1064D0 802E4C50 10620028 */  beq       $v1, $v0, .L802E4CF4
/* 1064D4 802E4C54 24020003 */   addiu    $v0, $zero, 3
/* 1064D8 802E4C58 1062002B */  beq       $v1, $v0, .L802E4D08
/* 1064DC 802E4C5C 00000000 */   nop
/* 1064E0 802E4C60 080B935C */  j         .L802E4D70
/* 1064E4 802E4C64 00000000 */   nop
.L802E4C68:
/* 1064E8 802E4C68 AE200058 */  sw        $zero, 0x58($s1)
/* 1064EC 802E4C6C 14A00057 */  bnez      $a1, .L802E4DCC
/* 1064F0 802E4C70 AE20005C */   sw       $zero, 0x5c($s1)
/* 1064F4 802E4C74 92020001 */  lbu       $v0, 1($s0)
/* 1064F8 802E4C78 24420001 */  addiu     $v0, $v0, 1
/* 1064FC 802E4C7C 080B935C */  j         .L802E4D70
/* 106500 802E4C80 A2020001 */   sb       $v0, 1($s0)
.L802E4C84:
/* 106504 802E4C84 C6200054 */  lwc1      $f0, 0x54($s1)
/* 106508 802E4C88 3C01802F */  lui       $at, %hi(D_802EB270)
/* 10650C 802E4C8C D422B270 */  ldc1      $f2, %lo(D_802EB270)($at)
/* 106510 802E4C90 46000021 */  cvt.d.s   $f0, $f0
/* 106514 802E4C94 46220000 */  add.d     $f0, $f0, $f2
/* 106518 802E4C98 3C013FF0 */  lui       $at, 0x3ff0
/* 10651C 802E4C9C 44811800 */  mtc1      $at, $f3
/* 106520 802E4CA0 44801000 */  mtc1      $zero, $f2
/* 106524 802E4CA4 46200020 */  cvt.s.d   $f0, $f0
/* 106528 802E4CA8 E6200054 */  swc1      $f0, 0x54($s1)
/* 10652C 802E4CAC 46000021 */  cvt.d.s   $f0, $f0
/* 106530 802E4CB0 4620103E */  c.le.d    $f2, $f0
/* 106534 802E4CB4 00000000 */  nop
/* 106538 802E4CB8 45000009 */  bc1f      .L802E4CE0
/* 10653C 802E4CBC 00000000 */   nop
/* 106540 802E4CC0 3C013F80 */  lui       $at, 0x3f80
/* 106544 802E4CC4 44810000 */  mtc1      $at, $f0
/* 106548 802E4CC8 00000000 */  nop
/* 10654C 802E4CCC E6200054 */  swc1      $f0, 0x54($s1)
/* 106550 802E4CD0 92020001 */  lbu       $v0, 1($s0)
/* 106554 802E4CD4 A2000002 */  sb        $zero, 2($s0)
/* 106558 802E4CD8 24420001 */  addiu     $v0, $v0, 1
/* 10655C 802E4CDC A2020001 */  sb        $v0, 1($s0)
.L802E4CE0:
/* 106560 802E4CE0 C6200054 */  lwc1      $f0, 0x54($s1)
/* 106564 802E4CE4 46000086 */  mov.s     $f2, $f0
/* 106568 802E4CE8 E620005C */  swc1      $f0, 0x5c($s1)
/* 10656C 802E4CEC 080B935C */  j         .L802E4D70
/* 106570 802E4CF0 E6220058 */   swc1     $f2, 0x58($s1)
.L802E4CF4:
/* 106574 802E4CF4 0C0B92C4 */  jal       entity_HeartBlockContent_set_initial_pos
/* 106578 802E4CF8 0220202D */   daddu    $a0, $s1, $zero
/* 10657C 802E4CFC 92020001 */  lbu       $v0, 1($s0)
/* 106580 802E4D00 24420001 */  addiu     $v0, $v0, 1
/* 106584 802E4D04 A2020001 */  sb        $v0, 1($s0)
.L802E4D08:
/* 106588 802E4D08 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* 10658C 802E4D0C 8C42A650 */  lw        $v0, %lo(gOverrideFlags)($v0)
/* 106590 802E4D10 14400017 */  bnez      $v0, .L802E4D70
/* 106594 802E4D14 00000000 */   nop
/* 106598 802E4D18 92020002 */  lbu       $v0, 2($s0)
/* 10659C 802E4D1C 2442FFFF */  addiu     $v0, $v0, -1
/* 1065A0 802E4D20 A2020002 */  sb        $v0, 2($s0)
/* 1065A4 802E4D24 00021600 */  sll       $v0, $v0, 0x18
/* 1065A8 802E4D28 1C400011 */  bgtz      $v0, .L802E4D70
/* 1065AC 802E4D2C 24020032 */   addiu    $v0, $zero, 0x32
/* 1065B0 802E4D30 9204000A */  lbu       $a0, 0xa($s0)
/* 1065B4 802E4D34 3C0141B0 */  lui       $at, 0x41b0
/* 1065B8 802E4D38 44810000 */  mtc1      $at, $f0
/* 1065BC 802E4D3C 3C014100 */  lui       $at, 0x4100
/* 1065C0 802E4D40 44811000 */  mtc1      $at, $f2
/* 1065C4 802E4D44 A2020002 */  sb        $v0, 2($s0)
/* 1065C8 802E4D48 24020004 */  addiu     $v0, $zero, 4
/* 1065CC 802E4D4C AFA20018 */  sw        $v0, 0x18($sp)
/* 1065D0 802E4D50 24020014 */  addiu     $v0, $zero, 0x14
/* 1065D4 802E4D54 AFA2001C */  sw        $v0, 0x1c($sp)
/* 1065D8 802E4D58 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1065DC 802E4D5C E7A20014 */  swc1      $f2, 0x14($sp)
/* 1065E0 802E4D60 8E250048 */  lw        $a1, 0x48($s1)
/* 1065E4 802E4D64 8E26004C */  lw        $a2, 0x4c($s1)
/* 1065E8 802E4D68 0C01C154 */  jal       playFX_22
/* 1065EC 802E4D6C 8E270050 */   lw       $a3, 0x50($s1)
.L802E4D70:
/* 1065F0 802E4D70 0C04417A */  jal       get_entity_by_index
/* 1065F4 802E4D74 92040000 */   lbu      $a0, ($s0)
/* 1065F8 802E4D78 0C0B836C */  jal       entity_can_collide_with_jumping_player
/* 1065FC 802E4D7C 0040202D */   daddu    $a0, $v0, $zero
/* 106600 802E4D80 10400012 */  beqz      $v0, .L802E4DCC
/* 106604 802E4D84 00000000 */   nop
/* 106608 802E4D88 0C043F5A */  jal       exec_entity_commandlist
/* 10660C 802E4D8C 0220202D */   daddu    $a0, $s1, $zero
/* 106610 802E4D90 0C03805E */  jal       disable_player_input
/* 106614 802E4D94 00000000 */   nop
/* 106618 802E4D98 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 10661C 802E4D9C 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 106620 802E4DA0 8C620004 */  lw        $v0, 4($v1)
/* 106624 802E4DA4 24040001 */  addiu     $a0, $zero, 1
/* 106628 802E4DA8 AC600054 */  sw        $zero, 0x54($v1)
/* 10662C 802E4DAC 34420200 */  ori       $v0, $v0, 0x200
/* 106630 802E4DB0 0C009C22 */  jal       set_time_freeze_mode
/* 106634 802E4DB4 AC620004 */   sw       $v0, 4($v1)
/* 106638 802E4DB8 3C03800A */  lui       $v1, %hi(gOverrideFlags)
/* 10663C 802E4DBC 2463A650 */  addiu     $v1, $v1, %lo(gOverrideFlags)
/* 106640 802E4DC0 8C620000 */  lw        $v0, ($v1)
/* 106644 802E4DC4 34420040 */  ori       $v0, $v0, 0x40
/* 106648 802E4DC8 AC620000 */  sw        $v0, ($v1)
.L802E4DCC:
/* 10664C 802E4DCC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 106650 802E4DD0 8FB10024 */  lw        $s1, 0x24($sp)
/* 106654 802E4DD4 8FB00020 */  lw        $s0, 0x20($sp)
/* 106658 802E4DD8 03E00008 */  jr        $ra
/* 10665C 802E4DDC 27BD0030 */   addiu    $sp, $sp, 0x30

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel show_damage_popup
/* 194E8C 802665AC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 194E90 802665B0 AFB00020 */  sw        $s0, 0x20($sp)
/* 194E94 802665B4 0000802D */  daddu     $s0, $zero, $zero
/* 194E98 802665B8 3C058029 */  lui       $a1, %hi(gDamageCountEffects)
/* 194E9C 802665BC 24A538AC */  addiu     $a1, $a1, %lo(gDamageCountEffects)
/* 194EA0 802665C0 44861000 */  mtc1      $a2, $f2
/* 194EA4 802665C4 8FA40038 */  lw        $a0, 0x38($sp)
/* 194EA8 802665C8 00A0182D */  daddu     $v1, $a1, $zero
/* 194EAC 802665CC AFBF0024 */  sw        $ra, 0x24($sp)
.L802665D0:
/* 194EB0 802665D0 8C620000 */  lw        $v0, ($v1)
/* 194EB4 802665D4 10400006 */  beqz      $v0, .L802665F0
/* 194EB8 802665D8 2A020018 */   slti     $v0, $s0, 0x18
/* 194EBC 802665DC 26100001 */  addiu     $s0, $s0, 1
/* 194EC0 802665E0 2A020018 */  slti      $v0, $s0, 0x18
/* 194EC4 802665E4 1440FFFA */  bnez      $v0, .L802665D0
/* 194EC8 802665E8 24630004 */   addiu    $v1, $v1, 4
/* 194ECC 802665EC 2A020018 */  slti      $v0, $s0, 0x18
.L802665F0:
/* 194ED0 802665F0 14400007 */  bnez      $v0, .L80266610
/* 194ED4 802665F4 00000000 */   nop
/* 194ED8 802665F8 8CA20000 */  lw        $v0, ($a1)
/* 194EDC 802665FC 0000802D */  daddu     $s0, $zero, $zero
/* 194EE0 80266600 8C43000C */  lw        $v1, 0xc($v0)
/* 194EE4 80266604 24020005 */  addiu     $v0, $zero, 5
/* 194EE8 80266608 AC620030 */  sw        $v0, 0x30($v1)
/* 194EEC 8026660C ACA00000 */  sw        $zero, ($a1)
.L80266610:
/* 194EF0 80266610 14800002 */  bnez      $a0, .L8026661C
/* 194EF4 80266614 24040037 */   addiu    $a0, $zero, 0x37
/* 194EF8 80266618 2404FFC9 */  addiu     $a0, $zero, -0x37
.L8026661C:
/* 194EFC 8026661C 44840000 */  mtc1      $a0, $f0
/* 194F00 80266620 00000000 */  nop
/* 194F04 80266624 46800020 */  cvt.s.w   $f0, $f0
/* 194F08 80266628 3C028029 */  lui       $v0, %hi(gDamageCountEffects)
/* 194F0C 8026662C 244238AC */  addiu     $v0, $v0, %lo(gDamageCountEffects)
/* 194F10 80266630 00108080 */  sll       $s0, $s0, 2
/* 194F14 80266634 E7A00014 */  swc1      $f0, 0x14($sp)
/* 194F18 80266638 3C014120 */  lui       $at, 0x4120
/* 194F1C 8026663C 44810000 */  mtc1      $at, $f0
/* 194F20 80266640 44056000 */  mfc1      $a1, $f12
/* 194F24 80266644 44067000 */  mfc1      $a2, $f14
/* 194F28 80266648 02021021 */  addu      $v0, $s0, $v0
/* 194F2C 8026664C AFA70018 */  sw        $a3, 0x18($sp)
/* 194F30 80266650 44071000 */  mfc1      $a3, $f2
/* 194F34 80266654 0000202D */  daddu     $a0, $zero, $zero
/* 194F38 80266658 AFA2001C */  sw        $v0, 0x1c($sp)
/* 194F3C 8026665C 0C01C0F4 */  jal       playFX_1E
/* 194F40 80266660 E7A00010 */   swc1     $f0, 0x10($sp)
/* 194F44 80266664 24020028 */  addiu     $v0, $zero, 0x28
/* 194F48 80266668 3C018029 */  lui       $at, %hi(gDamageCountTimers)
/* 194F4C 8026666C 00300821 */  addu      $at, $at, $s0
/* 194F50 80266670 AC22390C */  sw        $v0, %lo(gDamageCountTimers)($at)
/* 194F54 80266674 8FBF0024 */  lw        $ra, 0x24($sp)
/* 194F58 80266678 8FB00020 */  lw        $s0, 0x20($sp)
/* 194F5C 8026667C 03E00008 */  jr        $ra
/* 194F60 80266680 27BD0028 */   addiu    $sp, $sp, 0x28

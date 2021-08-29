.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DCC_E17B4C
/* E17B4C 80241DCC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E17B50 80241DD0 AFB40020 */  sw        $s4, 0x20($sp)
/* E17B54 80241DD4 0080A02D */  daddu     $s4, $a0, $zero
/* E17B58 80241DD8 0000202D */  daddu     $a0, $zero, $zero
/* E17B5C 80241DDC AFBF0024 */  sw        $ra, 0x24($sp)
/* E17B60 80241DE0 AFB3001C */  sw        $s3, 0x1c($sp)
/* E17B64 80241DE4 AFB20018 */  sw        $s2, 0x18($sp)
/* E17B68 80241DE8 AFB10014 */  sw        $s1, 0x14($sp)
/* E17B6C 80241DEC 0C00FB3A */  jal       get_enemy
/* E17B70 80241DF0 AFB00010 */   sw       $s0, 0x10($sp)
/* E17B74 80241DF4 8C51006C */  lw        $s1, 0x6c($v0)
/* E17B78 80241DF8 3C028888 */  lui       $v0, 0x8888
/* E17B7C 80241DFC 8E240008 */  lw        $a0, 8($s1)
/* E17B80 80241E00 34428889 */  ori       $v0, $v0, 0x8889
/* E17B84 80241E04 00820018 */  mult      $a0, $v0
/* E17B88 80241E08 3C014024 */  lui       $at, 0x4024
/* E17B8C 80241E0C 44811800 */  mtc1      $at, $f3
/* E17B90 80241E10 44801000 */  mtc1      $zero, $f2
/* E17B94 80241E14 00041FC3 */  sra       $v1, $a0, 0x1f
/* E17B98 80241E18 00003810 */  mfhi      $a3
/* E17B9C 80241E1C 00E41021 */  addu      $v0, $a3, $a0
/* E17BA0 80241E20 00021103 */  sra       $v0, $v0, 4
/* E17BA4 80241E24 00432823 */  subu      $a1, $v0, $v1
/* E17BA8 80241E28 00051100 */  sll       $v0, $a1, 4
/* E17BAC 80241E2C 00451023 */  subu      $v0, $v0, $a1
/* E17BB0 80241E30 00021040 */  sll       $v0, $v0, 1
/* E17BB4 80241E34 00822023 */  subu      $a0, $a0, $v0
/* E17BB8 80241E38 44840000 */  mtc1      $a0, $f0
/* E17BBC 80241E3C 00000000 */  nop
/* E17BC0 80241E40 46800020 */  cvt.s.w   $f0, $f0
/* E17BC4 80241E44 46000021 */  cvt.d.s   $f0, $f0
/* E17BC8 80241E48 46220002 */  mul.d     $f0, $f0, $f2
/* E17BCC 80241E4C 00000000 */  nop
/* E17BD0 80241E50 3C108011 */  lui       $s0, %hi(gPlayerData)
/* E17BD4 80241E54 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* E17BD8 80241E58 3C040001 */  lui       $a0, 1
/* E17BDC 80241E5C 00051080 */  sll       $v0, $a1, 2
/* E17BE0 80241E60 00451021 */  addu      $v0, $v0, $a1
/* E17BE4 80241E64 3C01403E */  lui       $at, 0x403e
/* E17BE8 80241E68 44811800 */  mtc1      $at, $f3
/* E17BEC 80241E6C 44801000 */  mtc1      $zero, $f2
/* E17BF0 80241E70 00021040 */  sll       $v0, $v0, 1
/* E17BF4 80241E74 46220003 */  div.d     $f0, $f0, $f2
/* E17BF8 80241E78 4620010D */  trunc.w.d $f4, $f0
/* E17BFC 80241E7C 44132000 */  mfc1      $s3, $f4
/* E17C00 80241E80 00000000 */  nop
/* E17C04 80241E84 00531021 */  addu      $v0, $v0, $s3
/* E17C08 80241E88 AE220020 */  sw        $v0, 0x20($s1)
/* E17C0C 80241E8C 8E030338 */  lw        $v1, 0x338($s0)
/* E17C10 80241E90 3484869F */  ori       $a0, $a0, 0x869f
/* E17C14 80241E94 00621821 */  addu      $v1, $v1, $v0
/* E17C18 80241E98 AE030338 */  sw        $v1, 0x338($s0)
/* E17C1C 80241E9C 0083182B */  sltu      $v1, $a0, $v1
/* E17C20 80241EA0 10600002 */  beqz      $v1, .L80241EAC
/* E17C24 80241EA4 0200902D */   daddu    $s2, $s0, $zero
/* E17C28 80241EA8 AE040338 */  sw        $a0, 0x338($s0)
.L80241EAC:
/* E17C2C 80241EAC 9642033C */  lhu       $v0, 0x33c($s2)
/* E17C30 80241EB0 8E230020 */  lw        $v1, 0x20($s1)
/* E17C34 80241EB4 0043102A */  slt       $v0, $v0, $v1
/* E17C38 80241EB8 10400003 */  beqz      $v0, .L80241EC8
/* E17C3C 80241EBC 00A0202D */   daddu    $a0, $a1, $zero
/* E17C40 80241EC0 96220022 */  lhu       $v0, 0x22($s1)
/* E17C44 80241EC4 A642033C */  sh        $v0, 0x33c($s2)
.L80241EC8:
/* E17C48 80241EC8 0C0496FA */  jal       set_message_value
/* E17C4C 80241ECC 0000282D */   daddu    $a1, $zero, $zero
/* E17C50 80241ED0 0260202D */  daddu     $a0, $s3, $zero
/* E17C54 80241ED4 0C0496FA */  jal       set_message_value
/* E17C58 80241ED8 24050001 */   addiu    $a1, $zero, 1
/* E17C5C 80241EDC 8E240020 */  lw        $a0, 0x20($s1)
/* E17C60 80241EE0 0C0496FA */  jal       set_message_value
/* E17C64 80241EE4 24050002 */   addiu    $a1, $zero, 2
/* E17C68 80241EE8 8E260020 */  lw        $a2, 0x20($s1)
/* E17C6C 80241EEC 14C00006 */  bnez      $a2, .L80241F08
/* E17C70 80241EF0 0280202D */   daddu    $a0, $s4, $zero
/* E17C74 80241EF4 8E230004 */  lw        $v1, 4($s1)
/* E17C78 80241EF8 2402000A */  addiu     $v0, $zero, 0xa
/* E17C7C 80241EFC 50620002 */  beql      $v1, $v0, .L80241F08
/* E17C80 80241F00 2406FFFF */   addiu    $a2, $zero, -1
/* E17C84 80241F04 0280202D */  daddu     $a0, $s4, $zero
.L80241F08:
/* E17C88 80241F08 3C05FE36 */  lui       $a1, 0xfe36
/* E17C8C 80241F0C 0C0B2026 */  jal       evt_set_variable
/* E17C90 80241F10 34A53C80 */   ori      $a1, $a1, 0x3c80
/* E17C94 80241F14 8FBF0024 */  lw        $ra, 0x24($sp)
/* E17C98 80241F18 8FB40020 */  lw        $s4, 0x20($sp)
/* E17C9C 80241F1C 8FB3001C */  lw        $s3, 0x1c($sp)
/* E17CA0 80241F20 8FB20018 */  lw        $s2, 0x18($sp)
/* E17CA4 80241F24 8FB10014 */  lw        $s1, 0x14($sp)
/* E17CA8 80241F28 8FB00010 */  lw        $s0, 0x10($sp)
/* E17CAC 80241F2C 24020002 */  addiu     $v0, $zero, 2
/* E17CB0 80241F30 03E00008 */  jr        $ra
/* E17CB4 80241F34 27BD0028 */   addiu    $sp, $sp, 0x28

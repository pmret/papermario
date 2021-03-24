.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_load_PRG
/* 2F9B4 800545B4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 2F9B8 800545B8 AFB20028 */  sw        $s2, 0x28($sp)
/* 2F9BC 800545BC 0080902D */  daddu     $s2, $a0, $zero
/* 2F9C0 800545C0 AFB00020 */  sw        $s0, 0x20($sp)
/* 2F9C4 800545C4 00A0802D */  daddu     $s0, $a1, $zero
/* 2F9C8 800545C8 0200202D */  daddu     $a0, $s0, $zero
/* 2F9CC 800545CC 27A50010 */  addiu     $a1, $sp, 0x10
/* 2F9D0 800545D0 24060010 */  addiu     $a2, $zero, 0x10
/* 2F9D4 800545D4 AFBF002C */  sw        $ra, 0x2c($sp)
/* 2F9D8 800545D8 0C015380 */  jal       snd_read_rom
/* 2F9DC 800545DC AFB10024 */   sw       $s1, 0x24($sp)
/* 2F9E0 800545E0 8FA20014 */  lw        $v0, 0x14($sp)
/* 2F9E4 800545E4 2451FFF0 */  addiu     $s1, $v0, -0x10
/* 2F9E8 800545E8 2E220201 */  sltiu     $v0, $s1, 0x201
/* 2F9EC 800545EC 14400002 */  bnez      $v0, .L800545F8
/* 2F9F0 800545F0 26040010 */   addiu    $a0, $s0, 0x10
/* 2F9F4 800545F4 24110200 */  addiu     $s1, $zero, 0x200
.L800545F8:
/* 2F9F8 800545F8 8E450058 */  lw        $a1, 0x58($s2)
/* 2F9FC 800545FC 0C015380 */  jal       snd_read_rom
/* 2FA00 80054600 0220302D */   daddu    $a2, $s1, $zero
/* 2FA04 80054604 001118C2 */  srl       $v1, $s1, 3
/* 2FA08 80054608 24020040 */  addiu     $v0, $zero, 0x40
/* 2FA0C 8005460C 00438823 */  subu      $s1, $v0, $v1
/* 2FA10 80054610 1A20000C */  blez      $s1, .L80054644
/* 2FA14 80054614 26440014 */   addiu    $a0, $s2, 0x14
/* 2FA18 80054618 24060008 */  addiu     $a2, $zero, 8
/* 2FA1C 8005461C 8E500058 */  lw        $s0, 0x58($s2)
/* 2FA20 80054620 000310C0 */  sll       $v0, $v1, 3
/* 2FA24 80054624 02028021 */  addu      $s0, $s0, $v0
/* 2FA28 80054628 0C0153DD */  jal       snd_copy_words
/* 2FA2C 8005462C 0200282D */   daddu    $a1, $s0, $zero
/* 2FA30 80054630 0200202D */  daddu     $a0, $s0, $zero
/* 2FA34 80054634 24850008 */  addiu     $a1, $a0, 8
/* 2FA38 80054638 001130C0 */  sll       $a2, $s1, 3
/* 2FA3C 8005463C 0C0153DD */  jal       snd_copy_words
/* 2FA40 80054640 24C6FFF8 */   addiu    $a2, $a2, -8
.L80054644:
/* 2FA44 80054644 8FBF002C */  lw        $ra, 0x2c($sp)
/* 2FA48 80054648 8FB20028 */  lw        $s2, 0x28($sp)
/* 2FA4C 8005464C 8FB10024 */  lw        $s1, 0x24($sp)
/* 2FA50 80054650 8FB00020 */  lw        $s0, 0x20($sp)
/* 2FA54 80054654 03E00008 */  jr        $ra
/* 2FA58 80054658 27BD0030 */   addiu    $sp, $sp, 0x30

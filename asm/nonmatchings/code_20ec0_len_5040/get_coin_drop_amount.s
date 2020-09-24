.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_coin_drop_amount
/* 24150 80048D50 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 24154 80048D54 AFB20018 */  sw        $s2, 0x18($sp)
/* 24158 80048D58 0080902D */  daddu     $s2, $a0, $zero
/* 2415C 80048D5C AFBF001C */  sw        $ra, 0x1c($sp)
/* 24160 80048D60 AFB10014 */  sw        $s1, 0x14($sp)
/* 24164 80048D64 AFB00010 */  sw        $s0, 0x10($sp)
/* 24168 80048D68 8E4200D4 */  lw        $v0, 0xd4($s2)
/* 2416C 80048D6C 3C11800B */  lui       $s1, 0x800b
/* 24170 80048D70 26310F10 */  addiu     $s1, $s1, 0xf10
/* 24174 80048D74 845000B2 */  lh        $s0, 0xb2($v0)
/* 24178 80048D78 844300B4 */  lh        $v1, 0xb4($v0)
/* 2417C 80048D7C 0070102A */  slt       $v0, $v1, $s0
/* 24180 80048D80 10400003 */  beqz      $v0, .L80048D90
/* 24184 80048D84 0200202D */   daddu    $a0, $s0, $zero
/* 24188 80048D88 0060802D */  daddu     $s0, $v1, $zero
/* 2418C 80048D8C 0080182D */  daddu     $v1, $a0, $zero
.L80048D90:
/* 24190 80048D90 06000003 */  bltz      $s0, .L80048DA0
/* 24194 80048D94 00702023 */   subu     $a0, $v1, $s0
/* 24198 80048D98 10800004 */  beqz      $a0, .L80048DAC
/* 2419C 80048D9C 00000000 */   nop      
.L80048DA0:
/* 241A0 80048DA0 0C00A67F */  jal       rand_int
/* 241A4 80048DA4 00000000 */   nop      
/* 241A8 80048DA8 00508021 */  addu      $s0, $v0, $s0
.L80048DAC:
/* 241AC 80048DAC 06020001 */  bltzl     $s0, .L80048DB4
/* 241B0 80048DB0 0000802D */   daddu    $s0, $zero, $zero
.L80048DB4:
/* 241B4 80048DB4 0C03A752 */  jal       is_ability_active
/* 241B8 80048DB8 24040019 */   addiu    $a0, $zero, 0x19
/* 241BC 80048DBC 10400004 */  beqz      $v0, .L80048DD0
/* 241C0 80048DC0 00000000 */   nop      
/* 241C4 80048DC4 9222000C */  lbu       $v0, 0xc($s1)
/* 241C8 80048DC8 00021042 */  srl       $v0, $v0, 1
/* 241CC 80048DCC 02028021 */  addu      $s0, $s0, $v0
.L80048DD0:
/* 241D0 80048DD0 8222000B */  lb        $v0, 0xb($s1)
/* 241D4 80048DD4 10400002 */  beqz      $v0, .L80048DE0
/* 241D8 80048DD8 00101040 */   sll      $v0, $s0, 1
/* 241DC 80048DDC 02028021 */  addu      $s0, $s0, $v0
.L80048DE0:
/* 241E0 80048DE0 0C03A752 */  jal       is_ability_active
/* 241E4 80048DE4 24040010 */   addiu    $a0, $zero, 0x10
/* 241E8 80048DE8 54400001 */  bnel      $v0, $zero, .L80048DF0
/* 241EC 80048DEC 00108040 */   sll      $s0, $s0, 1
.L80048DF0:
/* 241F0 80048DF0 8622000E */  lh        $v0, 0xe($s1)
/* 241F4 80048DF4 02028021 */  addu      $s0, $s0, $v0
/* 241F8 80048DF8 8E420000 */  lw        $v0, ($s2)
/* 241FC 80048DFC 3C030084 */  lui       $v1, 0x84
/* 24200 80048E00 00431024 */  and       $v0, $v0, $v1
/* 24204 80048E04 54400001 */  bnel      $v0, $zero, .L80048E0C
/* 24208 80048E08 0000802D */   daddu    $s0, $zero, $zero
.L80048E0C:
/* 2420C 80048E0C 2A020015 */  slti      $v0, $s0, 0x15
/* 24210 80048E10 50400001 */  beql      $v0, $zero, .L80048E18
/* 24214 80048E14 24100014 */   addiu    $s0, $zero, 0x14
.L80048E18:
/* 24218 80048E18 0200102D */  daddu     $v0, $s0, $zero
/* 2421C 80048E1C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 24220 80048E20 8FB20018 */  lw        $s2, 0x18($sp)
/* 24224 80048E24 8FB10014 */  lw        $s1, 0x14($sp)
/* 24228 80048E28 8FB00010 */  lw        $s0, 0x10($sp)
/* 2422C 80048E2C 03E00008 */  jr        $ra
/* 24230 80048E30 27BD0020 */   addiu    $sp, $sp, 0x20

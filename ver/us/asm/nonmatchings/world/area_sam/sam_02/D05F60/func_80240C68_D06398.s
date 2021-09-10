.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C68_D06398
/* D06398 80240C68 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D0639C 80240C6C AFB10024 */  sw        $s1, 0x24($sp)
/* D063A0 80240C70 0080882D */  daddu     $s1, $a0, $zero
/* D063A4 80240C74 3C05F840 */  lui       $a1, 0xf840
/* D063A8 80240C78 AFBF0044 */  sw        $ra, 0x44($sp)
/* D063AC 80240C7C AFBE0040 */  sw        $fp, 0x40($sp)
/* D063B0 80240C80 AFB7003C */  sw        $s7, 0x3c($sp)
/* D063B4 80240C84 AFB60038 */  sw        $s6, 0x38($sp)
/* D063B8 80240C88 AFB50034 */  sw        $s5, 0x34($sp)
/* D063BC 80240C8C AFB40030 */  sw        $s4, 0x30($sp)
/* D063C0 80240C90 AFB3002C */  sw        $s3, 0x2c($sp)
/* D063C4 80240C94 AFB20028 */  sw        $s2, 0x28($sp)
/* D063C8 80240C98 AFB00020 */  sw        $s0, 0x20($sp)
/* D063CC 80240C9C 8E3E0148 */  lw        $fp, 0x148($s1)
/* D063D0 80240CA0 0C0B1EAF */  jal       evt_get_variable
/* D063D4 80240CA4 34A56268 */   ori      $a1, $a1, 0x6268
/* D063D8 80240CA8 0040802D */  daddu     $s0, $v0, $zero
/* D063DC 80240CAC 0220202D */  daddu     $a0, $s1, $zero
/* D063E0 80240CB0 3C05F840 */  lui       $a1, 0xf840
/* D063E4 80240CB4 0C0B1EAF */  jal       evt_get_variable
/* D063E8 80240CB8 34A56269 */   ori      $a1, $a1, 0x6269
/* D063EC 80240CBC 0040B82D */  daddu     $s7, $v0, $zero
/* D063F0 80240CC0 0220202D */  daddu     $a0, $s1, $zero
/* D063F4 80240CC4 3C05F5DE */  lui       $a1, 0xf5de
/* D063F8 80240CC8 0C0B1EAF */  jal       evt_get_variable
/* D063FC 80240CCC 34A502DE */   ori      $a1, $a1, 0x2de
/* D06400 80240CD0 0040B02D */  daddu     $s6, $v0, $zero
/* D06404 80240CD4 0220202D */  daddu     $a0, $s1, $zero
/* D06408 80240CD8 3C05F5DE */  lui       $a1, 0xf5de
/* D0640C 80240CDC 0C0B1EAF */  jal       evt_get_variable
/* D06410 80240CE0 34A502DF */   ori      $a1, $a1, 0x2df
/* D06414 80240CE4 0040A82D */  daddu     $s5, $v0, $zero
/* D06418 80240CE8 93D3006D */  lbu       $s3, 0x6d($fp)
/* D0641C 80240CEC 32C2FFFF */  andi      $v0, $s6, 0xffff
/* D06420 80240CF0 A7B30010 */  sh        $s3, 0x10($sp)
/* D06424 80240CF4 93D2006E */  lbu       $s2, 0x6e($fp)
/* D06428 80240CF8 93C7006F */  lbu       $a3, 0x6f($fp)
/* D0642C 80240CFC 3274FFFF */  andi      $s4, $s3, 0xffff
/* D06430 80240D00 12820003 */  beq       $s4, $v0, .L80240D10
/* D06434 80240D04 A7A7001E */   sh       $a3, 0x1e($sp)
/* D06438 80240D08 0000B82D */  daddu     $s7, $zero, $zero
/* D0643C 80240D0C 02E0802D */  daddu     $s0, $s7, $zero
.L80240D10:
/* D06440 80240D10 3202FFFF */  andi      $v0, $s0, 0xffff
/* D06444 80240D14 14400016 */  bnez      $v0, .L80240D70
/* D06448 80240D18 0220202D */   daddu    $a0, $s1, $zero
/* D0644C 80240D1C 0C00A67F */  jal       rand_int
/* D06450 80240D20 24040064 */   addiu    $a0, $zero, 0x64
/* D06454 80240D24 2842001E */  slti      $v0, $v0, 0x1e
/* D06458 80240D28 10400011 */  beqz      $v0, .L80240D70
/* D0645C 80240D2C 0220202D */   daddu    $a0, $s1, $zero
/* D06460 80240D30 0C00A67F */  jal       rand_int
/* D06464 80240D34 2644FFFF */   addiu    $a0, $s2, -1
/* D06468 80240D38 0040A82D */  daddu     $s5, $v0, $zero
/* D0646C 80240D3C 0260B02D */  daddu     $s6, $s3, $zero
/* D06470 80240D40 0220202D */  daddu     $a0, $s1, $zero
/* D06474 80240D44 3C05F5DE */  lui       $a1, 0xf5de
/* D06478 80240D48 34A502DE */  ori       $a1, $a1, 0x2de
/* D0647C 80240D4C 0C0B2026 */  jal       evt_set_variable
/* D06480 80240D50 0280302D */   daddu    $a2, $s4, $zero
/* D06484 80240D54 0220202D */  daddu     $a0, $s1, $zero
/* D06488 80240D58 3C05F5DE */  lui       $a1, 0xf5de
/* D0648C 80240D5C 34A502DF */  ori       $a1, $a1, 0x2df
/* D06490 80240D60 0C0B2026 */  jal       evt_set_variable
/* D06494 80240D64 32A6FFFF */   andi     $a2, $s5, 0xffff
/* D06498 80240D68 24100001 */  addiu     $s0, $zero, 1
/* D0649C 80240D6C 0220202D */  daddu     $a0, $s1, $zero
.L80240D70:
/* D064A0 80240D70 3C05F840 */  lui       $a1, 0xf840
/* D064A4 80240D74 34A56268 */  ori       $a1, $a1, 0x6268
/* D064A8 80240D78 0C0B2026 */  jal       evt_set_variable
/* D064AC 80240D7C 3206FFFF */   andi     $a2, $s0, 0xffff
/* D064B0 80240D80 0220202D */  daddu     $a0, $s1, $zero
/* D064B4 80240D84 3C05F840 */  lui       $a1, 0xf840
/* D064B8 80240D88 34A56269 */  ori       $a1, $a1, 0x6269
/* D064BC 80240D8C 0C0B2026 */  jal       evt_set_variable
/* D064C0 80240D90 32E6FFFF */   andi     $a2, $s7, 0xffff
/* D064C4 80240D94 0000202D */  daddu     $a0, $zero, $zero
/* D064C8 80240D98 3C05F5DE */  lui       $a1, 0xf5de
/* D064CC 80240D9C 0C0B1EAF */  jal       evt_get_variable
/* D064D0 80240DA0 34A502E0 */   ori      $a1, $a1, 0x2e0
/* D064D4 80240DA4 0000202D */  daddu     $a0, $zero, $zero
/* D064D8 80240DA8 3C05F5DE */  lui       $a1, 0xf5de
/* D064DC 80240DAC 34A50180 */  ori       $a1, $a1, 0x180
/* D064E0 80240DB0 0C0B1EAF */  jal       evt_get_variable
/* D064E4 80240DB4 0040802D */   daddu    $s0, $v0, $zero
/* D064E8 80240DB8 0040282D */  daddu     $a1, $v0, $zero
/* D064EC 80240DBC 0000182D */  daddu     $v1, $zero, $zero
/* D064F0 80240DC0 3C068024 */  lui       $a2, %hi(D_80246C04_D0C334)
/* D064F4 80240DC4 24C66C04 */  addiu     $a2, $a2, %lo(D_80246C04_D0C334)
/* D064F8 80240DC8 00C0202D */  daddu     $a0, $a2, $zero
.L80240DCC:
/* D064FC 80240DCC 8C820000 */  lw        $v0, ($a0)
/* D06500 80240DD0 00A2102A */  slt       $v0, $a1, $v0
/* D06504 80240DD4 14400006 */  bnez      $v0, .L80240DF0
/* D06508 80240DD8 000310C0 */   sll      $v0, $v1, 3
/* D0650C 80240DDC 24630001 */  addiu     $v1, $v1, 1
/* D06510 80240DE0 28620008 */  slti      $v0, $v1, 8
/* D06514 80240DE4 1440FFF9 */  bnez      $v0, .L80240DCC
/* D06518 80240DE8 24840008 */   addiu    $a0, $a0, 8
/* D0651C 80240DEC 000310C0 */  sll       $v0, $v1, 3
.L80240DF0:
/* D06520 80240DF0 00461021 */  addu      $v0, $v0, $a2
/* D06524 80240DF4 8C420004 */  lw        $v0, 4($v0)
/* D06528 80240DF8 97A30010 */  lhu       $v1, 0x10($sp)
/* D0652C 80240DFC 0202202A */  slt       $a0, $s0, $v0
/* D06530 80240E00 32C2FFFF */  andi      $v0, $s6, 0xffff
/* D06534 80240E04 14620008 */  bne       $v1, $v0, .L80240E28
/* D06538 80240E08 32A2FFFF */   andi     $v0, $s5, 0xffff
/* D0653C 80240E0C 97A7001E */  lhu       $a3, 0x1e($sp)
/* D06540 80240E10 14E20005 */  bne       $a3, $v0, .L80240E28
/* D06544 80240E14 32E2FFFF */   andi     $v0, $s7, 0xffff
/* D06548 80240E18 14400003 */  bnez      $v0, .L80240E28
/* D0654C 80240E1C 00000000 */   nop
/* D06550 80240E20 14800008 */  bnez      $a0, .L80240E44
/* D06554 80240E24 24020001 */   addiu    $v0, $zero, 1
.L80240E28:
/* D06558 80240E28 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* D0655C 80240E2C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* D06560 80240E30 80420075 */  lb        $v0, 0x75($v0)
/* D06564 80240E34 10400005 */  beqz      $v0, .L80240E4C
/* D06568 80240E38 00000000 */   nop
/* D0656C 80240E3C 10800003 */  beqz      $a0, .L80240E4C
/* D06570 80240E40 24020001 */   addiu    $v0, $zero, 1
.L80240E44:
/* D06574 80240E44 08090396 */  j         .L80240E58
/* D06578 80240E48 AE220084 */   sw       $v0, 0x84($s1)
.L80240E4C:
/* D0657C 80240E4C 0C00F9EB */  jal       kill_enemy
/* D06580 80240E50 03C0202D */   daddu    $a0, $fp, $zero
/* D06584 80240E54 AE200084 */  sw        $zero, 0x84($s1)
.L80240E58:
/* D06588 80240E58 8FBF0044 */  lw        $ra, 0x44($sp)
/* D0658C 80240E5C 8FBE0040 */  lw        $fp, 0x40($sp)
/* D06590 80240E60 8FB7003C */  lw        $s7, 0x3c($sp)
/* D06594 80240E64 8FB60038 */  lw        $s6, 0x38($sp)
/* D06598 80240E68 8FB50034 */  lw        $s5, 0x34($sp)
/* D0659C 80240E6C 8FB40030 */  lw        $s4, 0x30($sp)
/* D065A0 80240E70 8FB3002C */  lw        $s3, 0x2c($sp)
/* D065A4 80240E74 8FB20028 */  lw        $s2, 0x28($sp)
/* D065A8 80240E78 8FB10024 */  lw        $s1, 0x24($sp)
/* D065AC 80240E7C 8FB00020 */  lw        $s0, 0x20($sp)
/* D065B0 80240E80 24020002 */  addiu     $v0, $zero, 2
/* D065B4 80240E84 03E00008 */  jr        $ra
/* D065B8 80240E88 27BD0048 */   addiu    $sp, $sp, 0x48

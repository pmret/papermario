.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel spr_draw_player_sprite
/* 100D30 802DDC40 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 100D34 802DDC44 308A00FF */  andi      $t2, $a0, 0xff
/* 100D38 802DDC48 000A1040 */  sll       $v0, $t2, 1
/* 100D3C 802DDC4C 004A1021 */  addu      $v0, $v0, $t2
/* 100D40 802DDC50 00021080 */  sll       $v0, $v0, 2
/* 100D44 802DDC54 2403FFFF */  addiu     $v1, $zero, -1
/* 100D48 802DDC58 AFBF0040 */  sw        $ra, 0x40($sp)
/* 100D4C 802DDC5C AFB7003C */  sw        $s7, 0x3c($sp)
/* 100D50 802DDC60 AFB60038 */  sw        $s6, 0x38($sp)
/* 100D54 802DDC64 AFB50034 */  sw        $s5, 0x34($sp)
/* 100D58 802DDC68 AFB40030 */  sw        $s4, 0x30($sp)
/* 100D5C 802DDC6C AFB3002C */  sw        $s3, 0x2c($sp)
/* 100D60 802DDC70 AFB20028 */  sw        $s2, 0x28($sp)
/* 100D64 802DDC74 AFB10024 */  sw        $s1, 0x24($sp)
/* 100D68 802DDC78 AFB00020 */  sw        $s0, 0x20($sp)
/* 100D6C 802DDC7C F7B40048 */  sdc1      $f20, 0x48($sp)
/* 100D70 802DDC80 3C09802E */  lui       $t1, %hi(D_802DF58C)
/* 100D74 802DDC84 01224821 */  addu      $t1, $t1, $v0
/* 100D78 802DDC88 8D29F58C */  lw        $t1, %lo(D_802DF58C)($t1)
/* 100D7C 802DDC8C 8FB70060 */  lw        $s7, 0x60($sp)
/* 100D80 802DDC90 11230080 */  beq       $t1, $v1, .L802DDE94
/* 100D84 802DDC94 0000102D */   daddu    $v0, $zero, $zero
/* 100D88 802DDC98 00091403 */  sra       $v0, $t1, 0x10
/* 100D8C 802DDC9C 304200FF */  andi      $v0, $v0, 0xff
/* 100D90 802DDCA0 2443FFFF */  addiu     $v1, $v0, -1
/* 100D94 802DDCA4 00031080 */  sll       $v0, $v1, 2
/* 100D98 802DDCA8 3C08802E */  lui       $t0, %hi(spr_playerSprites)
/* 100D9C 802DDCAC 01024021 */  addu      $t0, $t0, $v0
/* 100DA0 802DDCB0 8D08F548 */  lw        $t0, %lo(spr_playerSprites)($t0)
/* 100DA4 802DDCB4 3C01802E */  lui       $at, %hi(D_802DF57C)
/* 100DA8 802DDCB8 AC23F57C */  sw        $v1, %lo(D_802DF57C)($at)
/* 100DAC 802DDCBC 11000053 */  beqz      $t0, .L802DDE0C
/* 100DB0 802DDCC0 312200FF */   andi     $v0, $t1, 0xff
/* 100DB4 802DDCC4 8D140000 */  lw        $s4, ($t0)
/* 100DB8 802DDCC8 25080004 */  addiu     $t0, $t0, 4
/* 100DBC 802DDCCC 00021080 */  sll       $v0, $v0, 2
/* 100DC0 802DDCD0 01021021 */  addu      $v0, $t0, $v0
/* 100DC4 802DDCD4 8C52000C */  lw        $s2, 0xc($v0)
/* 100DC8 802DDCD8 3C020100 */  lui       $v0, 0x100
/* 100DCC 802DDCDC 01221024 */  and       $v0, $t1, $v0
/* 100DD0 802DDCE0 8D160000 */  lw        $s6, ($t0)
/* 100DD4 802DDCE4 10400013 */  beqz      $v0, .L802DDD34
/* 100DD8 802DDCE8 24020005 */   addiu    $v0, $zero, 5
/* 100DDC 802DDCEC 10620009 */  beq       $v1, $v0, .L802DDD14
/* 100DE0 802DDCF0 28620006 */   slti     $v0, $v1, 6
/* 100DE4 802DDCF4 10400005 */  beqz      $v0, .L802DDD0C
/* 100DE8 802DDCF8 24020009 */   addiu    $v0, $zero, 9
/* 100DEC 802DDCFC 10600005 */  beqz      $v1, .L802DDD14
/* 100DF0 802DDD00 3C024000 */   lui      $v0, 0x4000
/* 100DF4 802DDD04 080B774F */  j         .L802DDD3C
/* 100DF8 802DDD08 00821024 */   and      $v0, $a0, $v0
.L802DDD0C:
/* 100DFC 802DDD0C 1462000A */  bne       $v1, $v0, .L802DDD38
/* 100E00 802DDD10 3C024000 */   lui      $v0, 0x4000
.L802DDD14:
/* 100E04 802DDD14 24630001 */  addiu     $v1, $v1, 1
/* 100E08 802DDD18 00031080 */  sll       $v0, $v1, 2
/* 100E0C 802DDD1C 3C14802E */  lui       $s4, %hi(spr_playerSprites)
/* 100E10 802DDD20 0282A021 */  addu      $s4, $s4, $v0
/* 100E14 802DDD24 8E94F548 */  lw        $s4, %lo(spr_playerSprites)($s4)
/* 100E18 802DDD28 3C01802E */  lui       $at, %hi(D_802DF57C)
/* 100E1C 802DDD2C AC23F57C */  sw        $v1, %lo(D_802DF57C)($at)
/* 100E20 802DDD30 8E940000 */  lw        $s4, ($s4)
.L802DDD34:
/* 100E24 802DDD34 3C024000 */  lui       $v0, 0x4000
.L802DDD38:
/* 100E28 802DDD38 00821024 */  and       $v0, $a0, $v0
.L802DDD3C:
/* 100E2C 802DDD3C 14400019 */  bnez      $v0, .L802DDDA4
/* 100E30 802DDD40 24A2FFA5 */   addiu    $v0, $a1, -0x5b
/* 100E34 802DDD44 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* 100E38 802DDD48 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* 100E3C 802DDD4C 00031080 */  sll       $v0, $v1, 2
/* 100E40 802DDD50 00431021 */  addu      $v0, $v0, $v1
/* 100E44 802DDD54 00021080 */  sll       $v0, $v0, 2
/* 100E48 802DDD58 00431023 */  subu      $v0, $v0, $v1
/* 100E4C 802DDD5C 000218C0 */  sll       $v1, $v0, 3
/* 100E50 802DDD60 00431021 */  addu      $v0, $v0, $v1
/* 100E54 802DDD64 000210C0 */  sll       $v0, $v0, 3
/* 100E58 802DDD68 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 100E5C 802DDD6C 00220821 */  addu      $at, $at, $v0
/* 100E60 802DDD70 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 100E64 802DDD74 46000007 */  neg.s     $f0, $f0
/* 100E68 802DDD78 4600008D */  trunc.w.s $f2, $f0
/* 100E6C 802DDD7C 44021000 */  mfc1      $v0, $f2
/* 100E70 802DDD80 00000000 */  nop
/* 100E74 802DDD84 00A22821 */  addu      $a1, $a1, $v0
/* 100E78 802DDD88 28A20169 */  slti      $v0, $a1, 0x169
/* 100E7C 802DDD8C 50400001 */  beql      $v0, $zero, .L802DDD94
/* 100E80 802DDD90 24A5FE98 */   addiu    $a1, $a1, -0x168
.L802DDD94:
/* 100E84 802DDD94 28A2FE98 */  slti      $v0, $a1, -0x168
/* 100E88 802DDD98 54400001 */  bnel      $v0, $zero, .L802DDDA0
/* 100E8C 802DDD9C 24A50168 */   addiu    $a1, $a1, 0x168
.L802DDDA0:
/* 100E90 802DDDA0 24A2FFA5 */  addiu     $v0, $a1, -0x5b
.L802DDDA4:
/* 100E94 802DDDA4 2C4200B4 */  sltiu     $v0, $v0, 0xb4
/* 100E98 802DDDA8 14400004 */  bnez      $v0, .L802DDDBC
/* 100E9C 802DDDAC 24A2010E */   addiu    $v0, $a1, 0x10e
/* 100EA0 802DDDB0 2C4200B4 */  sltiu     $v0, $v0, 0xb4
/* 100EA4 802DDDB4 10400005 */  beqz      $v0, .L802DDDCC
/* 100EA8 802DDDB8 3C021000 */   lui      $v0, 0x1000
.L802DDDBC:
/* 100EAC 802DDDBC 3C01BFC0 */  lui       $at, 0xbfc0
/* 100EB0 802DDDC0 4481A000 */  mtc1      $at, $f20
/* 100EB4 802DDDC4 080B7775 */  j         .L802DDDD4
/* 100EB8 802DDDC8 3C021000 */   lui      $v0, 0x1000
.L802DDDCC:
/* 100EBC 802DDDCC 3C013FC0 */  lui       $at, 0x3fc0
/* 100EC0 802DDDD0 4481A000 */  mtc1      $at, $f20
.L802DDDD4:
/* 100EC4 802DDDD4 00821024 */  and       $v0, $a0, $v0
/* 100EC8 802DDDD8 10400004 */  beqz      $v0, .L802DDDEC
/* 100ECC 802DDDDC 00000000 */   nop
/* 100ED0 802DDDE0 44800000 */  mtc1      $zero, $f0
/* 100ED4 802DDDE4 00000000 */  nop
/* 100ED8 802DDDE8 46140501 */  sub.s     $f20, $f0, $f20
.L802DDDEC:
/* 100EDC 802DDDEC 3C02802E */  lui       $v0, %hi(D_802DFEA0)
/* 100EE0 802DDDF0 2442FEA0 */  addiu     $v0, $v0, %lo(D_802DFEA0)
/* 100EE4 802DDDF4 AC400000 */  sw        $zero, ($v0)
/* 100EE8 802DDDF8 AC450004 */  sw        $a1, 4($v0)
/* 100EEC 802DDDFC 04810005 */  bgez      $a0, .L802DDE14
/* 100EF0 802DDE00 AC400008 */   sw       $zero, 8($v0)
/* 100EF4 802DDE04 14C00004 */  bnez      $a2, .L802DDE18
/* 100EF8 802DDE08 30D300FF */   andi     $s3, $a2, 0xff
.L802DDE0C:
/* 100EFC 802DDE0C 080B77A5 */  j         .L802DDE94
/* 100F00 802DDE10 0000102D */   daddu    $v0, $zero, $zero
.L802DDE14:
/* 100F04 802DDE14 241300FF */  addiu     $s3, $zero, 0xff
.L802DDE18:
/* 100F08 802DDE18 000A1040 */  sll       $v0, $t2, 1
/* 100F0C 802DDE1C 004A1021 */  addu      $v0, $v0, $t2
/* 100F10 802DDE20 00021080 */  sll       $v0, $v0, 2
/* 100F14 802DDE24 3C10802E */  lui       $s0, %hi(spr_playerCurrentAnimInfo)
/* 100F18 802DDE28 02028021 */  addu      $s0, $s0, $v0
/* 100F1C 802DDE2C 8E10F588 */  lw        $s0, %lo(spr_playerCurrentAnimInfo)($s0)
/* 100F20 802DDE30 3C022000 */  lui       $v0, 0x2000
/* 100F24 802DDE34 00821024 */  and       $v0, $a0, $v0
/* 100F28 802DDE38 54400001 */  bnel      $v0, $zero, .L802DDE40
/* 100F2C 802DDE3C 00E0B02D */   daddu    $s6, $a3, $zero
.L802DDE40:
/* 100F30 802DDE40 8E030000 */  lw        $v1, ($s0)
/* 100F34 802DDE44 2402FFFF */  addiu     $v0, $zero, -1
/* 100F38 802DDE48 10620011 */  beq       $v1, $v0, .L802DDE90
/* 100F3C 802DDE4C 3C150800 */   lui      $s5, 0x800
/* 100F40 802DDE50 0040882D */  daddu     $s1, $v0, $zero
.L802DDE54:
/* 100F44 802DDE54 8E050000 */  lw        $a1, ($s0)
/* 100F48 802DDE58 02752025 */  or        $a0, $s3, $s5
/* 100F4C 802DDE5C AFB60010 */  sw        $s6, 0x10($sp)
/* 100F50 802DDE60 E7B40014 */  swc1      $f20, 0x14($sp)
/* 100F54 802DDE64 AFB70018 */  sw        $s7, 0x18($sp)
/* 100F58 802DDE68 8E460000 */  lw        $a2, ($s2)
/* 100F5C 802DDE6C 0C0B73B7 */  jal       spr_draw_component
/* 100F60 802DDE70 0280382D */   daddu    $a3, $s4, $zero
/* 100F64 802DDE74 8E420000 */  lw        $v0, ($s2)
/* 100F68 802DDE78 10510002 */  beq       $v0, $s1, .L802DDE84
/* 100F6C 802DDE7C 26100004 */   addiu    $s0, $s0, 4
/* 100F70 802DDE80 26520004 */  addiu     $s2, $s2, 4
.L802DDE84:
/* 100F74 802DDE84 8E020000 */  lw        $v0, ($s0)
/* 100F78 802DDE88 1451FFF2 */  bne       $v0, $s1, .L802DDE54
/* 100F7C 802DDE8C 00000000 */   nop
.L802DDE90:
/* 100F80 802DDE90 24020001 */  addiu     $v0, $zero, 1
.L802DDE94:
/* 100F84 802DDE94 8FBF0040 */  lw        $ra, 0x40($sp)
/* 100F88 802DDE98 8FB7003C */  lw        $s7, 0x3c($sp)
/* 100F8C 802DDE9C 8FB60038 */  lw        $s6, 0x38($sp)
/* 100F90 802DDEA0 8FB50034 */  lw        $s5, 0x34($sp)
/* 100F94 802DDEA4 8FB40030 */  lw        $s4, 0x30($sp)
/* 100F98 802DDEA8 8FB3002C */  lw        $s3, 0x2c($sp)
/* 100F9C 802DDEAC 8FB20028 */  lw        $s2, 0x28($sp)
/* 100FA0 802DDEB0 8FB10024 */  lw        $s1, 0x24($sp)
/* 100FA4 802DDEB4 8FB00020 */  lw        $s0, 0x20($sp)
/* 100FA8 802DDEB8 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 100FAC 802DDEBC 03E00008 */  jr        $ra
/* 100FB0 802DDEC0 27BD0050 */   addiu    $sp, $sp, 0x50

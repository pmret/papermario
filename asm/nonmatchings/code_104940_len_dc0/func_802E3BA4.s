.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E3BA4
/* 105424 802E3BA4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 105428 802E3BA8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 10542C 802E3BAC 0080882D */  daddu     $s1, $a0, $zero
/* 105430 802E3BB0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 105434 802E3BB4 AFB20020 */  sw        $s2, 0x20($sp)
/* 105438 802E3BB8 AFB00018 */  sw        $s0, 0x18($sp)
/* 10543C 802E3BBC 9222000B */  lbu       $v0, 0xb($s1)
/* 105440 802E3BC0 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 105444 802E3BC4 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 105448 802E3BC8 14400005 */  bnez      $v0, .L802E3BE0
/* 10544C 802E3BCC 00000000 */   nop
/* 105450 802E3BD0 92220006 */  lbu       $v0, 6($s1)
/* 105454 802E3BD4 30420001 */  andi      $v0, $v0, 1
/* 105458 802E3BD8 14400083 */  bnez      $v0, .L802E3DE8
/* 10545C 802E3BDC 0000102D */   daddu    $v0, $zero, $zero
.L802E3BE0:
/* 105460 802E3BE0 92230006 */  lbu       $v1, 6($s1)
/* 105464 802E3BE4 30620004 */  andi      $v0, $v1, 4
/* 105468 802E3BE8 10400016 */  beqz      $v0, .L802E3C44
/* 10546C 802E3BEC 30620080 */   andi     $v0, $v1, 0x80
/* 105470 802E3BF0 92240004 */  lbu       $a0, 4($s1)
/* 105474 802E3BF4 0C0441A9 */  jal       get_entity_type
/* 105478 802E3BF8 00000000 */   nop
/* 10547C 802E3BFC 0040182D */  daddu     $v1, $v0, $zero
/* 105480 802E3C00 2402000C */  addiu     $v0, $zero, 0xc
/* 105484 802E3C04 10620019 */  beq       $v1, $v0, .L802E3C6C
/* 105488 802E3C08 0062102A */   slt      $v0, $v1, $v0
/* 10548C 802E3C0C 14400005 */  bnez      $v0, .L802E3C24
/* 105490 802E3C10 2862001B */   slti     $v0, $v1, 0x1b
/* 105494 802E3C14 10400003 */  beqz      $v0, .L802E3C24
/* 105498 802E3C18 28620015 */   slti     $v0, $v1, 0x15
/* 10549C 802E3C1C 10400072 */  beqz      $v0, .L802E3DE8
/* 1054A0 802E3C20 0000102D */   daddu    $v0, $zero, $zero
.L802E3C24:
/* 1054A4 802E3C24 8E420000 */  lw        $v0, ($s2)
/* 1054A8 802E3C28 30420002 */  andi      $v0, $v0, 2
/* 1054AC 802E3C2C 1040006E */  beqz      $v0, .L802E3DE8
/* 1054B0 802E3C30 24020001 */   addiu    $v0, $zero, 1
.L802E3C34:
glabel L802E3C34_1054B4
/* 1054B4 802E3C34 0C043F5A */  jal       exec_entity_updatecmd
/* 1054B8 802E3C38 0220202D */   daddu    $a0, $s1, $zero
/* 1054BC 802E3C3C 080B8F7A */  j         .L802E3DE8
/* 1054C0 802E3C40 24020001 */   addiu    $v0, $zero, 1
.L802E3C44:
/* 1054C4 802E3C44 1440FFFB */  bnez      $v0, .L802E3C34
/* 1054C8 802E3C48 30620001 */   andi     $v0, $v1, 1
/* 1054CC 802E3C4C 1040000F */  beqz      $v0, .L802E3C8C
/* 1054D0 802E3C50 0000802D */   daddu    $s0, $zero, $zero
/* 1054D4 802E3C54 824300B4 */  lb        $v1, 0xb4($s2)
/* 1054D8 802E3C58 2402000D */  addiu     $v0, $zero, 0xd
/* 1054DC 802E3C5C 10620003 */  beq       $v1, $v0, .L802E3C6C
/* 1054E0 802E3C60 2402000F */   addiu    $v0, $zero, 0xf
/* 1054E4 802E3C64 14620003 */  bne       $v1, $v0, .L802E3C74
/* 1054E8 802E3C68 2402000E */   addiu    $v0, $zero, 0xe
.L802E3C6C:
/* 1054EC 802E3C6C 080B8F7A */  j         .L802E3DE8
/* 1054F0 802E3C70 0000102D */   daddu    $v0, $zero, $zero
.L802E3C74:
/* 1054F4 802E3C74 10620003 */  beq       $v1, $v0, .L802E3C84
/* 1054F8 802E3C78 24020010 */   addiu    $v0, $zero, 0x10
/* 1054FC 802E3C7C 1462005A */  bne       $v1, $v0, .L802E3DE8
/* 105500 802E3C80 24020001 */   addiu    $v0, $zero, 1
.L802E3C84:
/* 105504 802E3C84 080B8F2A */  j         .L802E3CA8
/* 105508 802E3C88 24100001 */   addiu    $s0, $zero, 1
.L802E3C8C:
/* 10550C 802E3C8C 30620040 */  andi      $v0, $v1, 0x40
/* 105510 802E3C90 10400054 */  beqz      $v0, .L802E3DE4
/* 105514 802E3C94 3C030100 */   lui      $v1, 0x100
/* 105518 802E3C98 8E420000 */  lw        $v0, ($s2)
/* 10551C 802E3C9C 00431024 */  and       $v0, $v0, $v1
/* 105520 802E3CA0 10400051 */  beqz      $v0, .L802E3DE8
/* 105524 802E3CA4 24020001 */   addiu    $v0, $zero, 1
.L802E3CA8:
/* 105528 802E3CA8 92240004 */  lbu       $a0, 4($s1)
/* 10552C 802E3CAC 0C0441A9 */  jal       get_entity_type
/* 105530 802E3CB0 00000000 */   nop
/* 105534 802E3CB4 2443FFF5 */  addiu     $v1, $v0, -0xb
/* 105538 802E3CB8 2C620015 */  sltiu     $v0, $v1, 0x15
/* 10553C 802E3CBC 10400049 */  beqz      $v0, .L802E3DE4
/* 105540 802E3CC0 00031080 */   sll      $v0, $v1, 2
/* 105544 802E3CC4 3C01802F */  lui       $at, %hi(jtbl_802EB210)
/* 105548 802E3CC8 00220821 */  addu      $at, $at, $v0
/* 10554C 802E3CCC 8C22B210 */  lw        $v0, %lo(jtbl_802EB210)($at)
/* 105550 802E3CD0 00400008 */  jr        $v0
/* 105554 802E3CD4 00000000 */   nop
glabel L802E3CD8_105558
/* 105558 802E3CD8 12000007 */  beqz      $s0, .L802E3CF8
/* 10555C 802E3CDC 00000000 */   nop
/* 105560 802E3CE0 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 105564 802E3CE4 8042F290 */  lb        $v0, %lo(gPlayerData)($v0)
/* 105568 802E3CE8 58400007 */  blezl     $v0, .L802E3D08
/* 10556C 802E3CEC 0000802D */   daddu    $s0, $zero, $zero
/* 105570 802E3CF0 080B8F42 */  j         .L802E3D08
/* 105574 802E3CF4 00000000 */   nop
.L802E3CF8:
/* 105578 802E3CF8 3C028011 */  lui       $v0, %hi(gPlayerData+0x1)
/* 10557C 802E3CFC 8042F291 */  lb        $v0, %lo(gPlayerData+0x1)($v0)
/* 105580 802E3D00 04430001 */  bgezl     $v0, .L802E3D08
/* 105584 802E3D04 24100001 */   addiu    $s0, $zero, 1
.L802E3D08:
/* 105588 802E3D08 12000037 */  beqz      $s0, .L802E3DE8
/* 10558C 802E3D0C 24020001 */   addiu    $v0, $zero, 1
/* 105590 802E3D10 3C05802F */  lui       $a1, %hi(D_802E9E80)
/* 105594 802E3D14 24A59E80 */  addiu     $a1, $a1, %lo(D_802E9E80)
/* 105598 802E3D18 0C043EF0 */  jal       set_entity_updatecmd
/* 10559C 802E3D1C 0220202D */   daddu    $a0, $s1, $zero
/* 1055A0 802E3D20 C6200050 */  lwc1      $f0, 0x50($s1)
/* 1055A4 802E3D24 080B8F6C */  j         .L802E3DB0
/* 1055A8 802E3D28 2404014F */   addiu    $a0, $zero, 0x14f
glabel L802E3D2C_1055AC
/* 1055AC 802E3D2C 12000008 */  beqz      $s0, .L802E3D50
/* 1055B0 802E3D30 00000000 */   nop
/* 1055B4 802E3D34 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 1055B8 802E3D38 8042F290 */  lb        $v0, %lo(gPlayerData)($v0)
/* 1055BC 802E3D3C 28420002 */  slti      $v0, $v0, 2
/* 1055C0 802E3D40 54400007 */  bnel      $v0, $zero, .L802E3D60
/* 1055C4 802E3D44 0000802D */   daddu    $s0, $zero, $zero
/* 1055C8 802E3D48 080B8F58 */  j         .L802E3D60
/* 1055CC 802E3D4C 00000000 */   nop
.L802E3D50:
/* 1055D0 802E3D50 3C028011 */  lui       $v0, %hi(gPlayerData+0x1)
/* 1055D4 802E3D54 8042F291 */  lb        $v0, %lo(gPlayerData+0x1)($v0)
/* 1055D8 802E3D58 5C400001 */  bgtzl     $v0, .L802E3D60
/* 1055DC 802E3D5C 24100001 */   addiu    $s0, $zero, 1
.L802E3D60:
/* 1055E0 802E3D60 12000021 */  beqz      $s0, .L802E3DE8
/* 1055E4 802E3D64 24020001 */   addiu    $v0, $zero, 1
/* 1055E8 802E3D68 3C05802F */  lui       $a1, %hi(D_802E9E80)
/* 1055EC 802E3D6C 24A59E80 */  addiu     $a1, $a1, %lo(D_802E9E80)
/* 1055F0 802E3D70 0C043EF0 */  jal       set_entity_updatecmd
/* 1055F4 802E3D74 0220202D */   daddu    $a0, $s1, $zero
/* 1055F8 802E3D78 C6200050 */  lwc1      $f0, 0x50($s1)
/* 1055FC 802E3D7C 080B8F6C */  j         .L802E3DB0
/* 105600 802E3D80 24040150 */   addiu    $a0, $zero, 0x150
glabel L802E3D84_105604
/* 105604 802E3D84 3C028011 */  lui       $v0, %hi(gPlayerData+0x1)
/* 105608 802E3D88 8042F291 */  lb        $v0, %lo(gPlayerData+0x1)($v0)
/* 10560C 802E3D8C 28420002 */  slti      $v0, $v0, 2
/* 105610 802E3D90 14400015 */  bnez      $v0, .L802E3DE8
/* 105614 802E3D94 24020001 */   addiu    $v0, $zero, 1
/* 105618 802E3D98 3C05802F */  lui       $a1, %hi(D_802E9E80)
/* 10561C 802E3D9C 24A59E80 */  addiu     $a1, $a1, %lo(D_802E9E80)
/* 105620 802E3DA0 0C043EF0 */  jal       set_entity_updatecmd
/* 105624 802E3DA4 0220202D */   daddu    $a0, $s1, $zero
/* 105628 802E3DA8 C6200050 */  lwc1      $f0, 0x50($s1)
/* 10562C 802E3DAC 24040151 */  addiu     $a0, $zero, 0x151
.L802E3DB0:
/* 105630 802E3DB0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 105634 802E3DB4 8E260048 */  lw        $a2, 0x48($s1)
/* 105638 802E3DB8 8E27004C */  lw        $a3, 0x4c($s1)
/* 10563C 802E3DBC 0C052757 */  jal       play_sound_at_position
/* 105640 802E3DC0 0000282D */   daddu    $a1, $zero, $zero
/* 105644 802E3DC4 080B8F7A */  j         .L802E3DE8
/* 105648 802E3DC8 24020001 */   addiu    $v0, $zero, 1
glabel L802E3DCC_10564C
/* 10564C 802E3DCC 0C04419E */  jal       func_80110678
/* 105650 802E3DD0 0220202D */   daddu    $a0, $s1, $zero
/* 105654 802E3DD4 080B8F0D */  j         .L802E3C34
/* 105658 802E3DD8 00000000 */   nop
glabel L802E3DDC_10565C
/* 10565C 802E3DDC 0C04419E */  jal       func_80110678
/* 105660 802E3DE0 0220202D */   daddu    $a0, $s1, $zero
.L802E3DE4:
glabel L802E3DE4_105664
/* 105664 802E3DE4 24020001 */  addiu     $v0, $zero, 1
.L802E3DE8:
/* 105668 802E3DE8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 10566C 802E3DEC 8FB20020 */  lw        $s2, 0x20($sp)
/* 105670 802E3DF0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 105674 802E3DF4 8FB00018 */  lw        $s0, 0x18($sp)
/* 105678 802E3DF8 03E00008 */  jr        $ra
/* 10567C 802E3DFC 27BD0028 */   addiu    $sp, $sp, 0x28

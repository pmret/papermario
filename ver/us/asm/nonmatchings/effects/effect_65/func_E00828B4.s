.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00828B4
/* 385EF4 E00828B4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 385EF8 E00828B8 AFB50024 */  sw        $s5, 0x24($sp)
/* 385EFC E00828BC 0080A82D */  daddu     $s5, $a0, $zero
/* 385F00 E00828C0 3C06DB06 */  lui       $a2, 0xdb06
/* 385F04 E00828C4 34C60024 */  ori       $a2, $a2, 0x24
/* 385F08 E00828C8 AFB20018 */  sw        $s2, 0x18($sp)
/* 385F0C E00828CC 24120001 */  addiu     $s2, $zero, 1
/* 385F10 E00828D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 385F14 E00828D4 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* 385F18 E00828D8 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* 385F1C E00828DC 3C02E700 */  lui       $v0, 0xe700
/* 385F20 E00828E0 AFBF0034 */  sw        $ra, 0x34($sp)
/* 385F24 E00828E4 AFBE0030 */  sw        $fp, 0x30($sp)
/* 385F28 E00828E8 AFB7002C */  sw        $s7, 0x2c($sp)
/* 385F2C E00828EC AFB60028 */  sw        $s6, 0x28($sp)
/* 385F30 E00828F0 AFB40020 */  sw        $s4, 0x20($sp)
/* 385F34 E00828F4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 385F38 E00828F8 AFB10014 */  sw        $s1, 0x14($sp)
/* 385F3C E00828FC 8E050000 */  lw        $a1, ($s0)
/* 385F40 E0082900 8EB1000C */  lw        $s1, 0xc($s5)
/* 385F44 E0082904 00A0182D */  daddu     $v1, $a1, $zero
/* 385F48 E0082908 24A50008 */  addiu     $a1, $a1, 8
/* 385F4C E008290C 0220202D */  daddu     $a0, $s1, $zero
/* 385F50 E0082910 AE050000 */  sw        $a1, ($s0)
/* 385F54 E0082914 AC620000 */  sw        $v0, ($v1)
/* 385F58 E0082918 AC600004 */  sw        $zero, 4($v1)
/* 385F5C E008291C ACA60000 */  sw        $a2, ($a1)
/* 385F60 E0082920 8EA30010 */  lw        $v1, 0x10($s5)
/* 385F64 E0082924 24A20008 */  addiu     $v0, $a1, 8
/* 385F68 E0082928 AE020000 */  sw        $v0, ($s0)
/* 385F6C E008292C 8C62001C */  lw        $v0, 0x1c($v1)
/* 385F70 E0082930 3C038000 */  lui       $v1, 0x8000
/* 385F74 E0082934 00431021 */  addu      $v0, $v0, $v1
/* 385F78 E0082938 0C020960 */  jal       func_E0082580
/* 385F7C E008293C ACA20004 */   sw       $v0, 4($a1)
/* 385F80 E0082940 8E360038 */  lw        $s6, 0x38($s1)
/* 385F84 E0082944 8E330000 */  lw        $s3, ($s1)
/* 385F88 E0082948 8EA20008 */  lw        $v0, 8($s5)
/* 385F8C E008294C 0242102A */  slt       $v0, $s2, $v0
/* 385F90 E0082950 10400030 */  beqz      $v0, .LE0082A14
/* 385F94 E0082954 26310048 */   addiu    $s1, $s1, 0x48
/* 385F98 E0082958 0240F02D */  daddu     $fp, $s2, $zero
/* 385F9C E008295C 3C14DE00 */  lui       $s4, 0xde00
/* 385FA0 E0082960 3C170900 */  lui       $s7, 0x900
/* 385FA4 E0082964 26F72198 */  addiu     $s7, $s7, 0x2198
.LE0082968:
/* 385FA8 E0082968 1EC00003 */  bgtz      $s6, .LE0082978
/* 385FAC E008296C 2407000A */   addiu    $a3, $zero, 0xa
/* 385FB0 E0082970 56670024 */  bnel      $s3, $a3, .LE0082A04
/* 385FB4 E0082974 26520001 */   addiu    $s2, $s2, 1
.LE0082978:
/* 385FB8 E0082978 167E0008 */  bne       $s3, $fp, .LE008299C
/* 385FBC E008297C 00000000 */   nop
/* 385FC0 E0082980 8E020000 */  lw        $v0, ($s0)
/* 385FC4 E0082984 0040182D */  daddu     $v1, $v0, $zero
/* 385FC8 E0082988 24420008 */  addiu     $v0, $v0, 8
/* 385FCC E008298C AE020000 */  sw        $v0, ($s0)
/* 385FD0 E0082990 AC740000 */  sw        $s4, ($v1)
/* 385FD4 E0082994 08020A6F */  j         .LE00829BC
/* 385FD8 E0082998 AC770004 */   sw       $s7, 4($v1)
.LE008299C:
/* 385FDC E008299C 8E020000 */  lw        $v0, ($s0)
/* 385FE0 E00829A0 0040182D */  daddu     $v1, $v0, $zero
/* 385FE4 E00829A4 24420008 */  addiu     $v0, $v0, 8
/* 385FE8 E00829A8 AE020000 */  sw        $v0, ($s0)
/* 385FEC E00829AC 3C020900 */  lui       $v0, 0x900
/* 385FF0 E00829B0 24422100 */  addiu     $v0, $v0, 0x2100
/* 385FF4 E00829B4 AC740000 */  sw        $s4, ($v1)
/* 385FF8 E00829B8 AC620004 */  sw        $v0, 4($v1)
.LE00829BC:
/* 385FFC E00829BC 0C0209B1 */  jal       func_E00826C4
/* 386000 E00829C0 0220202D */   daddu    $a0, $s1, $zero
/* 386004 E00829C4 3C05D838 */  lui       $a1, 0xd838
/* 386008 E00829C8 34A50002 */  ori       $a1, $a1, 2
/* 38600C E00829CC 8E030000 */  lw        $v1, ($s0)
/* 386010 E00829D0 3C020900 */  lui       $v0, 0x900
/* 386014 E00829D4 24422230 */  addiu     $v0, $v0, 0x2230
/* 386018 E00829D8 0060202D */  daddu     $a0, $v1, $zero
/* 38601C E00829DC 24630008 */  addiu     $v1, $v1, 8
/* 386020 E00829E0 AE030000 */  sw        $v1, ($s0)
/* 386024 E00829E4 AC820004 */  sw        $v0, 4($a0)
/* 386028 E00829E8 24620008 */  addiu     $v0, $v1, 8
/* 38602C E00829EC AC940000 */  sw        $s4, ($a0)
/* 386030 E00829F0 AE020000 */  sw        $v0, ($s0)
/* 386034 E00829F4 24020040 */  addiu     $v0, $zero, 0x40
/* 386038 E00829F8 AC650000 */  sw        $a1, ($v1)
/* 38603C E00829FC AC620004 */  sw        $v0, 4($v1)
/* 386040 E0082A00 26520001 */  addiu     $s2, $s2, 1
.LE0082A04:
/* 386044 E0082A04 8EA20008 */  lw        $v0, 8($s5)
/* 386048 E0082A08 0242102A */  slt       $v0, $s2, $v0
/* 38604C E0082A0C 1440FFD6 */  bnez      $v0, .LE0082968
/* 386050 E0082A10 26310048 */   addiu    $s1, $s1, 0x48
.LE0082A14:
/* 386054 E0082A14 3C03D838 */  lui       $v1, 0xd838
/* 386058 E0082A18 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 38605C E0082A1C 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 386060 E0082A20 8C820000 */  lw        $v0, ($a0)
/* 386064 E0082A24 34630002 */  ori       $v1, $v1, 2
/* 386068 E0082A28 0040282D */  daddu     $a1, $v0, $zero
/* 38606C E0082A2C 24420008 */  addiu     $v0, $v0, 8
/* 386070 E0082A30 AC820000 */  sw        $v0, ($a0)
/* 386074 E0082A34 ACA30000 */  sw        $v1, ($a1)
/* 386078 E0082A38 24030040 */  addiu     $v1, $zero, 0x40
/* 38607C E0082A3C ACA30004 */  sw        $v1, 4($a1)
/* 386080 E0082A40 24430008 */  addiu     $v1, $v0, 8
/* 386084 E0082A44 AC830000 */  sw        $v1, ($a0)
/* 386088 E0082A48 3C03E700 */  lui       $v1, 0xe700
/* 38608C E0082A4C AC430000 */  sw        $v1, ($v0)
/* 386090 E0082A50 AC400004 */  sw        $zero, 4($v0)
/* 386094 E0082A54 8FBF0034 */  lw        $ra, 0x34($sp)
/* 386098 E0082A58 8FBE0030 */  lw        $fp, 0x30($sp)
/* 38609C E0082A5C 8FB7002C */  lw        $s7, 0x2c($sp)
/* 3860A0 E0082A60 8FB60028 */  lw        $s6, 0x28($sp)
/* 3860A4 E0082A64 8FB50024 */  lw        $s5, 0x24($sp)
/* 3860A8 E0082A68 8FB40020 */  lw        $s4, 0x20($sp)
/* 3860AC E0082A6C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3860B0 E0082A70 8FB20018 */  lw        $s2, 0x18($sp)
/* 3860B4 E0082A74 8FB10014 */  lw        $s1, 0x14($sp)
/* 3860B8 E0082A78 8FB00010 */  lw        $s0, 0x10($sp)
/* 3860BC E0082A7C 03E00008 */  jr        $ra
/* 3860C0 E0082A80 27BD0038 */   addiu    $sp, $sp, 0x38

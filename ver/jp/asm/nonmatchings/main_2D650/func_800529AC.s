.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800529AC
/* 2DDAC 800529AC 240A00FC */  addiu     $t2, $zero, 0xfc
/* 2DDB0 800529B0 240900FB */  addiu     $t1, $zero, 0xfb
/* 2DDB4 800529B4 240800FD */  addiu     $t0, $zero, 0xfd
/* 2DDB8 800529B8 240700FE */  addiu     $a3, $zero, 0xfe
/* 2DDBC 800529BC 24060080 */  addiu     $a2, $zero, 0x80
.L800529C0:
/* 2DDC0 800529C0 8C85001C */  lw        $a1, 0x1c($a0)
/* 2DDC4 800529C4 90A30000 */  lbu       $v1, ($a1)
/* 2DDC8 800529C8 80A20000 */  lb        $v0, ($a1)
/* 2DDCC 800529CC 24A50001 */  addiu     $a1, $a1, 1
/* 2DDD0 800529D0 0441003B */  bgez      $v0, .L80052AC0
/* 2DDD4 800529D4 AC85001C */   sw       $a1, 0x1c($a0)
/* 2DDD8 800529D8 306300FF */  andi      $v1, $v1, 0xff
/* 2DDDC 800529DC 106A0023 */  beq       $v1, $t2, .L80052A6C
/* 2DDE0 800529E0 286200FD */   slti     $v0, $v1, 0xfd
/* 2DDE4 800529E4 10400005 */  beqz      $v0, .L800529FC
/* 2DDE8 800529E8 00000000 */   nop
/* 2DDEC 800529EC 10690025 */  beq       $v1, $t1, .L80052A84
/* 2DDF0 800529F0 24A20001 */   addiu    $v0, $a1, 1
/* 2DDF4 800529F4 08014AAC */  j         .L80052AB0
/* 2DDF8 800529F8 00000000 */   nop
.L800529FC:
/* 2DDFC 800529FC 1068000B */  beq       $v1, $t0, .L80052A2C
/* 2DE00 80052A00 00000000 */   nop
/* 2DE04 80052A04 1467002A */  bne       $v1, $a3, .L80052AB0
/* 2DE08 80052A08 24A20001 */   addiu    $v0, $a1, 1
/* 2DE0C 80052A0C 90A30000 */  lbu       $v1, ($a1)
/* 2DE10 80052A10 AC82001C */  sw        $v0, 0x1c($a0)
/* 2DE14 80052A14 306200FF */  andi      $v0, $v1, 0xff
/* 2DE18 80052A18 2C420081 */  sltiu     $v0, $v0, 0x81
/* 2DE1C 80052A1C 50400001 */  beql      $v0, $zero, .L80052A24
/* 2DE20 80052A20 24030080 */   addiu    $v1, $zero, 0x80
.L80052A24:
/* 2DE24 80052A24 08014A70 */  j         .L800529C0
/* 2DE28 80052A28 AC830030 */   sw       $v1, 0x30($a0)
.L80052A2C:
/* 2DE2C 80052A2C 80A30000 */  lb        $v1, ($a1)
/* 2DE30 80052A30 8C820030 */  lw        $v0, 0x30($a0)
/* 2DE34 80052A34 00431021 */  addu      $v0, $v0, $v1
/* 2DE38 80052A38 AC820030 */  sw        $v0, 0x30($a0)
/* 2DE3C 80052A3C 0040182D */  daddu     $v1, $v0, $zero
/* 2DE40 80052A40 24A20001 */  addiu     $v0, $a1, 1
/* 2DE44 80052A44 AC82001C */  sw        $v0, 0x1c($a0)
/* 2DE48 80052A48 28620081 */  slti      $v0, $v1, 0x81
/* 2DE4C 80052A4C 14400003 */  bnez      $v0, .L80052A5C
/* 2DE50 80052A50 00000000 */   nop
/* 2DE54 80052A54 08014A70 */  j         .L800529C0
/* 2DE58 80052A58 AC860030 */   sw       $a2, 0x30($a0)
.L80052A5C:
/* 2DE5C 80052A5C 0462FFD8 */  bltzl     $v1, .L800529C0
/* 2DE60 80052A60 AC800030 */   sw       $zero, 0x30($a0)
/* 2DE64 80052A64 08014A70 */  j         .L800529C0
/* 2DE68 80052A68 00000000 */   nop
.L80052A6C:
/* 2DE6C 80052A6C 90A30000 */  lbu       $v1, ($a1)
/* 2DE70 80052A70 24A20001 */  addiu     $v0, $a1, 1
/* 2DE74 80052A74 AC82001C */  sw        $v0, 0x1c($a0)
/* 2DE78 80052A78 AC820034 */  sw        $v0, 0x34($a0)
/* 2DE7C 80052A7C 08014A70 */  j         .L800529C0
/* 2DE80 80052A80 A0830038 */   sb       $v1, 0x38($a0)
.L80052A84:
/* 2DE84 80052A84 90830038 */  lbu       $v1, 0x38($a0)
/* 2DE88 80052A88 10600006 */  beqz      $v1, .L80052AA4
/* 2DE8C 80052A8C AC82001C */   sw       $v0, 0x1c($a0)
/* 2DE90 80052A90 2462FFFF */  addiu     $v0, $v1, -1
/* 2DE94 80052A94 A0820038 */  sb        $v0, 0x38($a0)
/* 2DE98 80052A98 304200FF */  andi      $v0, $v0, 0xff
/* 2DE9C 80052A9C 1040FFC8 */  beqz      $v0, .L800529C0
/* 2DEA0 80052AA0 00000000 */   nop
.L80052AA4:
/* 2DEA4 80052AA4 8C820034 */  lw        $v0, 0x34($a0)
/* 2DEA8 80052AA8 08014A70 */  j         .L800529C0
/* 2DEAC 80052AAC AC82001C */   sw       $v0, 0x1c($a0)
.L80052AB0:
/* 2DEB0 80052AB0 8C82001C */  lw        $v0, 0x1c($a0)
/* 2DEB4 80052AB4 24420001 */  addiu     $v0, $v0, 1
/* 2DEB8 80052AB8 08014A70 */  j         .L800529C0
/* 2DEBC 80052ABC AC82001C */   sw       $v0, 0x1c($a0)
.L80052AC0:
/* 2DEC0 80052AC0 03E00008 */  jr        $ra
/* 2DEC4 80052AC4 0060102D */   daddu    $v0, $v1, $zero

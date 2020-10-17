.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuGfxTaskMgr
/* 7E40 8002CA40 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 7E44 8002CA44 3C04800E */  lui       $a0, 0x800e
/* 7E48 8002CA48 2484AC90 */  addiu     $a0, $a0, -0x5370
/* 7E4C 8002CA4C 3C05800A */  lui       $a1, 0x800a
/* 7E50 8002CA50 24A5E6D0 */  addiu     $a1, $a1, -0x1930
/* 7E54 8002CA54 24060008 */  addiu     $a2, $zero, 8
/* 7E58 8002CA58 AFBF0028 */  sw        $ra, 0x28($sp)
/* 7E5C 8002CA5C AFB30024 */  sw        $s3, 0x24($sp)
/* 7E60 8002CA60 AFB20020 */  sw        $s2, 0x20($sp)
/* 7E64 8002CA64 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7E68 8002CA68 0C019560 */  jal       osCreateMesgQueue
/* 7E6C 8002CA6C AFB00018 */   sw       $s0, 0x18($sp)
/* 7E70 8002CA70 24130004 */  addiu     $s3, $zero, 4
/* 7E74 8002CA74 24120008 */  addiu     $s2, $zero, 8
/* 7E78 8002CA78 3C11800A */  lui       $s1, %hi(nuGfxDisplay)
/* 7E7C 8002CA7C 2631A5F8 */  addiu     $s1, $s1, %lo(nuGfxDisplay)
/* 7E80 8002CA80 3C10800A */  lui       $s0, %hi(nuGfxTaskSpool)
/* 7E84 8002CA84 2610A618 */  addiu     $s0, $s0, %lo(nuGfxTaskSpool)
.L8002CA88:
/* 7E88 8002CA88 3C04800E */  lui       $a0, 0x800e
/* 7E8C 8002CA8C 2484AC90 */  addiu     $a0, $a0, -0x5370
/* 7E90 8002CA90 27A50010 */  addiu     $a1, $sp, 0x10
/* 7E94 8002CA94 0C0195BC */  jal       osRecvMesg
/* 7E98 8002CA98 24060001 */   addiu    $a2, $zero, 1
/* 7E9C 8002CA9C 8FA40010 */  lw        $a0, 0x10($sp)
/* 7EA0 8002CAA0 8C820054 */  lw        $v0, 0x54($a0)
/* 7EA4 8002CAA4 84420000 */  lh        $v0, ($v0)
/* 7EA8 8002CAA8 10530005 */  beq       $v0, $s3, .L8002CAC0
/* 7EAC 8002CAAC 00000000 */   nop      
/* 7EB0 8002CAB0 10520012 */  beq       $v0, $s2, .L8002CAFC
/* 7EB4 8002CAB4 00000000 */   nop      
/* 7EB8 8002CAB8 0800B2A2 */  j         .L8002CA88
/* 7EBC 8002CABC 00000000 */   nop      
.L8002CAC0:
/* 7EC0 8002CAC0 3C028007 */  lui       $v0, 0x8007
/* 7EC4 8002CAC4 8C4273F4 */  lw        $v0, 0x73f4($v0)
/* 7EC8 8002CAC8 10400003 */  beqz      $v0, .L8002CAD8
/* 7ECC 8002CACC 00000000 */   nop      
/* 7ED0 8002CAD0 0040F809 */  jalr      $v0
/* 7ED4 8002CAD4 00000000 */   nop      
.L8002CAD8:
/* 7ED8 8002CAD8 8E220000 */  lw        $v0, ($s1)
/* 7EDC 8002CADC 30420080 */  andi      $v0, $v0, 0x80
/* 7EE0 8002CAE0 1040000C */  beqz      $v0, .L8002CB14
/* 7EE4 8002CAE4 00000000 */   nop      
/* 7EE8 8002CAE8 0C019CE0 */  jal       osViBlack
/* 7EEC 8002CAEC 0000202D */   daddu    $a0, $zero, $zero
/* 7EF0 8002CAF0 24020001 */  addiu     $v0, $zero, 1
/* 7EF4 8002CAF4 0800B2C5 */  j         .L8002CB14
/* 7EF8 8002CAF8 AE220000 */   sw       $v0, ($s1)
.L8002CAFC:
/* 7EFC 8002CAFC 3C028007 */  lui       $v0, 0x8007
/* 7F00 8002CB00 8C4273F8 */  lw        $v0, 0x73f8($v0)
/* 7F04 8002CB04 10400003 */  beqz      $v0, .L8002CB14
/* 7F08 8002CB08 00000000 */   nop      
/* 7F0C 8002CB0C 0040F809 */  jalr      $v0
/* 7F10 8002CB10 00000000 */   nop      
.L8002CB14:
/* 7F14 8002CB14 0C018250 */  jal       osSetIntMask
/* 7F18 8002CB18 24040001 */   addiu    $a0, $zero, 1
/* 7F1C 8002CB1C 8E030000 */  lw        $v1, ($s0)
/* 7F20 8002CB20 0040202D */  daddu     $a0, $v0, $zero
/* 7F24 8002CB24 2463FFFF */  addiu     $v1, $v1, -1
/* 7F28 8002CB28 0C018250 */  jal       osSetIntMask
/* 7F2C 8002CB2C AE030000 */   sw       $v1, ($s0)
/* 7F30 8002CB30 0800B2A2 */  j         .L8002CA88
/* 7F34 8002CB34 00000000 */   nop      

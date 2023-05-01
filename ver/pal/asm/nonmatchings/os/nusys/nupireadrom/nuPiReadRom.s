.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

/* Generated by spimdisasm 1.11.1 */

glabel nuPiReadRom
/* 3AF30 8005FB30 27BDFFA0 */  addiu      $sp, $sp, -0x60
/* 3AF34 8005FB34 AFB30054 */  sw         $s3, 0x54($sp)
/* 3AF38 8005FB38 0080982D */  daddu      $s3, $a0, $zero
/* 3AF3C 8005FB3C AFB20050 */  sw         $s2, 0x50($sp)
/* 3AF40 8005FB40 00A0902D */  daddu      $s2, $a1, $zero
/* 3AF44 8005FB44 AFB1004C */  sw         $s1, 0x4C($sp)
/* 3AF48 8005FB48 00C0882D */  daddu      $s1, $a2, $zero
/* 3AF4C 8005FB4C AFB00048 */  sw         $s0, 0x48($sp)
/* 3AF50 8005FB50 27B00028 */  addiu      $s0, $sp, 0x28
/* 3AF54 8005FB54 0200202D */  daddu      $a0, $s0, $zero
/* 3AF58 8005FB58 27A50040 */  addiu      $a1, $sp, 0x40
/* 3AF5C 8005FB5C AFBF0058 */  sw         $ra, 0x58($sp)
/* 3AF60 8005FB60 0C0198FC */  jal        osCreateMesgQueue
/* 3AF64 8005FB64 24060001 */   addiu     $a2, $zero, 0x1
/* 3AF68 8005FB68 0240202D */  daddu      $a0, $s2, $zero
/* 3AF6C 8005FB6C 0220282D */  daddu      $a1, $s1, $zero
/* 3AF70 8005FB70 A3A00012 */  sb         $zero, 0x12($sp)
/* 3AF74 8005FB74 0C018964 */  jal        osInvalDCache
/* 3AF78 8005FB78 AFB00014 */   sw        $s0, 0x14($sp)
/* 3AF7C 8005FB7C 12200015 */  beqz       $s1, .LPAL_8005FBD4
/* 3AF80 8005FB80 00000000 */   nop
.LPAL_8005FB84:
/* 3AF84 8005FB84 2E224001 */  sltiu      $v0, $s1, 0x4001
/* 3AF88 8005FB88 14400002 */  bnez       $v0, .LPAL_8005FB94
/* 3AF8C 8005FB8C 0220802D */   daddu     $s0, $s1, $zero
/* 3AF90 8005FB90 24104000 */  addiu      $s0, $zero, 0x4000
.LPAL_8005FB94:
/* 3AF94 8005FB94 27A50010 */  addiu      $a1, $sp, 0x10
/* 3AF98 8005FB98 3C048009 */  lui        $a0, %hi(nuPiCartHandle)
/* 3AF9C 8005FB9C 8C846A10 */  lw         $a0, %lo(nuPiCartHandle)($a0)
/* 3AFA0 8005FBA0 0000302D */  daddu      $a2, $zero, $zero
/* 3AFA4 8005FBA4 AFB20018 */  sw         $s2, 0x18($sp)
/* 3AFA8 8005FBA8 AFB3001C */  sw         $s3, 0x1C($sp)
/* 3AFAC 8005FBAC 0C018564 */  jal        osEPiStartDma
/* 3AFB0 8005FBB0 AFB00020 */   sw        $s0, 0x20($sp)
/* 3AFB4 8005FBB4 27A40028 */  addiu      $a0, $sp, 0x28
/* 3AFB8 8005FBB8 27A50040 */  addiu      $a1, $sp, 0x40
/* 3AFBC 8005FBBC 0C019958 */  jal        osRecvMesg
/* 3AFC0 8005FBC0 24060001 */   addiu     $a2, $zero, 0x1
/* 3AFC4 8005FBC4 02709821 */  addu       $s3, $s3, $s0
/* 3AFC8 8005FBC8 02308823 */  subu       $s1, $s1, $s0
/* 3AFCC 8005FBCC 1620FFED */  bnez       $s1, .LPAL_8005FB84
/* 3AFD0 8005FBD0 02509021 */   addu      $s2, $s2, $s0
.LPAL_8005FBD4:
/* 3AFD4 8005FBD4 8FBF0058 */  lw         $ra, 0x58($sp)
/* 3AFD8 8005FBD8 8FB30054 */  lw         $s3, 0x54($sp)
/* 3AFDC 8005FBDC 8FB20050 */  lw         $s2, 0x50($sp)
/* 3AFE0 8005FBE0 8FB1004C */  lw         $s1, 0x4C($sp)
/* 3AFE4 8005FBE4 8FB00048 */  lw         $s0, 0x48($sp)
/* 3AFE8 8005FBE8 03E00008 */  jr         $ra
/* 3AFEC 8005FBEC 27BD0060 */   addiu     $sp, $sp, 0x60
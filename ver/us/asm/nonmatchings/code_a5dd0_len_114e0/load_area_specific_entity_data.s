.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel load_area_specific_entity_data
/* A7314 80110C14 3C028015 */  lui       $v0, %hi(D_8015132C)
/* A7318 80110C18 8C42132C */  lw        $v0, %lo(D_8015132C)($v0)
/* A731C 80110C1C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A7320 80110C20 14400022 */  bnez      $v0, .L80110CAC
/* A7324 80110C24 AFBF0010 */   sw       $ra, 0x10($sp)
/* A7328 80110C28 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* A732C 80110C2C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* A7330 80110C30 84430086 */  lh        $v1, 0x86($v0)
/* A7334 80110C34 24020011 */  addiu     $v0, $zero, 0x11
/* A7338 80110C38 10620003 */  beq       $v1, $v0, .L80110C48
/* A733C 80110C3C 24020008 */   addiu    $v0, $zero, 8
/* A7340 80110C40 14620007 */  bne       $v1, $v0, .L80110C60
/* A7344 80110C44 2402000A */   addiu    $v0, $zero, 0xa
.L80110C48:
/* A7348 80110C48 3C0400E3 */  lui       $a0, 0xe3
/* A734C 80110C4C 2484D730 */  addiu     $a0, $a0, -0x28d0
/* A7350 80110C50 3C0500E3 */  lui       $a1, 0xe3
/* A7354 80110C54 24A5F750 */  addiu     $a1, $a1, -0x8b0
/* A7358 80110C58 08044326 */  j         .L80110C98
/* A735C 80110C5C 3C06802B */   lui      $a2, 0x802b
.L80110C60:
/* A7360 80110C60 10620003 */  beq       $v1, $v0, .L80110C70
/* A7364 80110C64 24020010 */   addiu    $v0, $zero, 0x10
/* A7368 80110C68 14620007 */  bne       $v1, $v0, .L80110C88
/* A736C 80110C6C 3C06802B */   lui      $a2, 0x802b
.L80110C70:
/* A7370 80110C70 3C0400E3 */  lui       $a0, 0xe3
/* A7374 80110C74 2484F750 */  addiu     $a0, $a0, -0x8b0
/* A7378 80110C78 3C0500E3 */  lui       $a1, 0xe3
/* A737C 80110C7C 24A51530 */  addiu     $a1, $a1, 0x1530
/* A7380 80110C80 08044326 */  j         .L80110C98
/* A7384 80110C84 3C06802B */   lui      $a2, 0x802b
.L80110C88:
/* A7388 80110C88 3C0400E3 */  lui       $a0, 0xe3
/* A738C 80110C8C 2484B530 */  addiu     $a0, $a0, -0x4ad0
/* A7390 80110C90 3C0500E3 */  lui       $a1, 0xe3
/* A7394 80110C94 24A5D730 */  addiu     $a1, $a1, -0x28d0
.L80110C98:
/* A7398 80110C98 0C00A5CF */  jal       dma_copy
/* A739C 80110C9C 34C6AE00 */   ori      $a2, $a2, 0xae00
/* A73A0 80110CA0 24020001 */  addiu     $v0, $zero, 1
/* A73A4 80110CA4 3C018015 */  lui       $at, %hi(D_8015132C)
/* A73A8 80110CA8 AC22132C */  sw        $v0, %lo(D_8015132C)($at)
.L80110CAC:
/* A73AC 80110CAC 8FBF0010 */  lw        $ra, 0x10($sp)
/* A73B0 80110CB0 03E00008 */  jr        $ra
/* A73B4 80110CB4 27BD0018 */   addiu    $sp, $sp, 0x18

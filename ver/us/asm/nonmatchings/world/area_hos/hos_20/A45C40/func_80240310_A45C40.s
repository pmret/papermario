.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_A45C40
/* A45C40 80240310 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* A45C44 80240314 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* A45C48 80240318 8C620000 */  lw        $v0, ($v1)
/* A45C4C 8024031C AC8000A4 */  sw        $zero, 0xa4($a0)
/* A45C50 80240320 8C420010 */  lw        $v0, 0x10($v0)
/* A45C54 80240324 30428000 */  andi      $v0, $v0, 0x8000
/* A45C58 80240328 10400002 */  beqz      $v0, .L80240334
/* A45C5C 8024032C 24020001 */   addiu    $v0, $zero, 1
/* A45C60 80240330 AC8200A4 */  sw        $v0, 0xa4($a0)
.L80240334:
/* A45C64 80240334 8C620000 */  lw        $v0, ($v1)
/* A45C68 80240338 8C420010 */  lw        $v0, 0x10($v0)
/* A45C6C 8024033C 30424000 */  andi      $v0, $v0, 0x4000
/* A45C70 80240340 10400002 */  beqz      $v0, .L8024034C
/* A45C74 80240344 24020001 */   addiu    $v0, $zero, 1
/* A45C78 80240348 AC8200A4 */  sw        $v0, 0xa4($a0)
.L8024034C:
/* A45C7C 8024034C 03E00008 */  jr        $ra
/* A45C80 80240350 24020002 */   addiu    $v0, $zero, 2
/* A45C84 80240354 00000000 */  nop
/* A45C88 80240358 00000000 */  nop
/* A45C8C 8024035C 00000000 */  nop

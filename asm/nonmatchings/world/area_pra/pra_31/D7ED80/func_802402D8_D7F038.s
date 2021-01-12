.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402D8_D7F038
/* D7F038 802402D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7F03C 802402DC AFBF0010 */  sw        $ra, 0x10($sp)
/* D7F040 802402E0 8C82000C */  lw        $v0, 0xc($a0)
/* D7F044 802402E4 0C0B1EAF */  jal       get_variable
/* D7F048 802402E8 8C450000 */   lw       $a1, ($v0)
/* D7F04C 802402EC 0040182D */  daddu     $v1, $v0, $zero
/* D7F050 802402F0 10600012 */  beqz      $v1, .L8024033C
/* D7F054 802402F4 0000202D */   daddu    $a0, $zero, $zero
/* D7F058 802402F8 8C620000 */  lw        $v0, ($v1)
/* D7F05C 802402FC 5040000A */  beql      $v0, $zero, .L80240328
/* D7F060 80240300 00041080 */   sll      $v0, $a0, 2
/* D7F064 80240304 3C058024 */  lui       $a1, %hi(D_80247CA0)
/* D7F068 80240308 24A57CA0 */  addiu     $a1, $a1, %lo(D_80247CA0)
.L8024030C:
/* D7F06C 8024030C 24630004 */  addiu     $v1, $v1, 4
/* D7F070 80240310 24840001 */  addiu     $a0, $a0, 1
/* D7F074 80240314 ACA20000 */  sw        $v0, ($a1)
/* D7F078 80240318 8C620000 */  lw        $v0, ($v1)
/* D7F07C 8024031C 1440FFFB */  bnez      $v0, .L8024030C
/* D7F080 80240320 24A50004 */   addiu    $a1, $a1, 4
/* D7F084 80240324 00041080 */  sll       $v0, $a0, 2
.L80240328:
/* D7F088 80240328 3C018024 */  lui       $at, %hi(D_80247CA0)
/* D7F08C 8024032C 00220821 */  addu      $at, $at, $v0
/* D7F090 80240330 AC207CA0 */  sw        $zero, %lo(D_80247CA0)($at)
/* D7F094 80240334 080900D9 */  j         .L80240364
/* D7F098 80240338 00000000 */   nop
.L8024033C:
/* D7F09C 8024033C 3C038024 */  lui       $v1, %hi(D_80247CA0)
/* D7F0A0 80240340 24637CA0 */  addiu     $v1, $v1, %lo(D_80247CA0)
/* D7F0A4 80240344 0060282D */  daddu     $a1, $v1, $zero
.L80240348:
/* D7F0A8 80240348 24820010 */  addiu     $v0, $a0, 0x10
/* D7F0AC 8024034C AC620000 */  sw        $v0, ($v1)
/* D7F0B0 80240350 24630004 */  addiu     $v1, $v1, 4
/* D7F0B4 80240354 24840001 */  addiu     $a0, $a0, 1
/* D7F0B8 80240358 28820070 */  slti      $v0, $a0, 0x70
/* D7F0BC 8024035C 1440FFFA */  bnez      $v0, .L80240348
/* D7F0C0 80240360 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80240364:
/* D7F0C4 80240364 8FBF0010 */  lw        $ra, 0x10($sp)
/* D7F0C8 80240368 24020002 */  addiu     $v0, $zero, 2
/* D7F0CC 8024036C 03E00008 */  jr        $ra
/* D7F0D0 80240370 27BD0018 */   addiu    $sp, $sp, 0x18

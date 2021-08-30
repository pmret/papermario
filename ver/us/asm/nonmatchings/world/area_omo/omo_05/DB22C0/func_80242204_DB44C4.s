.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242204_DB44C4
/* DB44C4 80242204 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DB44C8 80242208 AFBF0010 */  sw        $ra, 0x10($sp)
/* DB44CC 8024220C 8C82000C */  lw        $v0, 0xc($a0)
/* DB44D0 80242210 0C0B1EAF */  jal       evt_get_variable
/* DB44D4 80242214 8C450000 */   lw       $a1, ($v0)
/* DB44D8 80242218 0040182D */  daddu     $v1, $v0, $zero
/* DB44DC 8024221C 10600012 */  beqz      $v1, .L80242268
/* DB44E0 80242220 0000202D */   daddu    $a0, $zero, $zero
/* DB44E4 80242224 8C620000 */  lw        $v0, ($v1)
/* DB44E8 80242228 5040000A */  beql      $v0, $zero, .L80242254
/* DB44EC 8024222C 00041080 */   sll      $v0, $a0, 2
/* DB44F0 80242230 3C058024 */  lui       $a1, %hi(D_80245650)
/* DB44F4 80242234 24A55650 */  addiu     $a1, $a1, %lo(D_80245650)
.L80242238:
/* DB44F8 80242238 24630004 */  addiu     $v1, $v1, 4
/* DB44FC 8024223C 24840001 */  addiu     $a0, $a0, 1
/* DB4500 80242240 ACA20000 */  sw        $v0, ($a1)
/* DB4504 80242244 8C620000 */  lw        $v0, ($v1)
/* DB4508 80242248 1440FFFB */  bnez      $v0, .L80242238
/* DB450C 8024224C 24A50004 */   addiu    $a1, $a1, 4
/* DB4510 80242250 00041080 */  sll       $v0, $a0, 2
.L80242254:
/* DB4514 80242254 3C018024 */  lui       $at, %hi(D_80245650)
/* DB4518 80242258 00220821 */  addu      $at, $at, $v0
/* DB451C 8024225C AC205650 */  sw        $zero, %lo(D_80245650)($at)
/* DB4520 80242260 080908A4 */  j         .L80242290
/* DB4524 80242264 00000000 */   nop
.L80242268:
/* DB4528 80242268 3C038024 */  lui       $v1, %hi(D_80245650)
/* DB452C 8024226C 24635650 */  addiu     $v1, $v1, %lo(D_80245650)
/* DB4530 80242270 0060282D */  daddu     $a1, $v1, $zero
.L80242274:
/* DB4534 80242274 24820080 */  addiu     $v0, $a0, 0x80
/* DB4538 80242278 AC620000 */  sw        $v0, ($v1)
/* DB453C 8024227C 24630004 */  addiu     $v1, $v1, 4
/* DB4540 80242280 24840001 */  addiu     $a0, $a0, 1
/* DB4544 80242284 2882005B */  slti      $v0, $a0, 0x5b
/* DB4548 80242288 1440FFFA */  bnez      $v0, .L80242274
/* DB454C 8024228C ACA0016C */   sw       $zero, 0x16c($a1)
.L80242290:
/* DB4550 80242290 8FBF0010 */  lw        $ra, 0x10($sp)
/* DB4554 80242294 24020002 */  addiu     $v0, $zero, 2
/* DB4558 80242298 03E00008 */  jr        $ra
/* DB455C 8024229C 27BD0018 */   addiu    $sp, $sp, 0x18

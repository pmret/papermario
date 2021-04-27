.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BB0_BBDD50
/* BBDD50 80240BB0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BBDD54 80240BB4 AFBF0010 */  sw        $ra, 0x10($sp)
/* BBDD58 80240BB8 8C82000C */  lw        $v0, 0xc($a0)
/* BBDD5C 80240BBC 0C0B1EAF */  jal       get_variable
/* BBDD60 80240BC0 8C450000 */   lw       $a1, ($v0)
/* BBDD64 80240BC4 0040182D */  daddu     $v1, $v0, $zero
/* BBDD68 80240BC8 10600012 */  beqz      $v1, .L80240C14
/* BBDD6C 80240BCC 0000202D */   daddu    $a0, $zero, $zero
/* BBDD70 80240BD0 8C620000 */  lw        $v0, ($v1)
/* BBDD74 80240BD4 5040000A */  beql      $v0, $zero, .L80240C00
/* BBDD78 80240BD8 00041080 */   sll      $v0, $a0, 2
/* BBDD7C 80240BDC 3C058024 */  lui       $a1, %hi(flo_08_shakeTreeEvent_Tree1)
/* BBDD80 80240BE0 24A558F0 */  addiu     $a1, $a1, %lo(flo_08_shakeTreeEvent_Tree1)
.L80240BE4:
/* BBDD84 80240BE4 24630004 */  addiu     $v1, $v1, 4
/* BBDD88 80240BE8 24840001 */  addiu     $a0, $a0, 1
/* BBDD8C 80240BEC ACA20000 */  sw        $v0, ($a1)
/* BBDD90 80240BF0 8C620000 */  lw        $v0, ($v1)
/* BBDD94 80240BF4 1440FFFB */  bnez      $v0, .L80240BE4
/* BBDD98 80240BF8 24A50004 */   addiu    $a1, $a1, 4
/* BBDD9C 80240BFC 00041080 */  sll       $v0, $a0, 2
.L80240C00:
/* BBDDA0 80240C00 3C018024 */  lui       $at, %hi(flo_08_shakeTreeEvent_Tree1)
/* BBDDA4 80240C04 00220821 */  addu      $at, $at, $v0
/* BBDDA8 80240C08 AC2058F0 */  sw        $zero, %lo(flo_08_shakeTreeEvent_Tree1)($at)
/* BBDDAC 80240C0C 0809030F */  j         .L80240C3C
/* BBDDB0 80240C10 00000000 */   nop
.L80240C14:
/* BBDDB4 80240C14 3C038024 */  lui       $v1, %hi(flo_08_shakeTreeEvent_Tree1)
/* BBDDB8 80240C18 246358F0 */  addiu     $v1, $v1, %lo(flo_08_shakeTreeEvent_Tree1)
/* BBDDBC 80240C1C 0060282D */  daddu     $a1, $v1, $zero
.L80240C20:
/* BBDDC0 80240C20 24820010 */  addiu     $v0, $a0, 0x10
/* BBDDC4 80240C24 AC620000 */  sw        $v0, ($v1)
/* BBDDC8 80240C28 24630004 */  addiu     $v1, $v1, 4
/* BBDDCC 80240C2C 24840001 */  addiu     $a0, $a0, 1
/* BBDDD0 80240C30 28820070 */  slti      $v0, $a0, 0x70
/* BBDDD4 80240C34 1440FFFA */  bnez      $v0, .L80240C20
/* BBDDD8 80240C38 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80240C3C:
/* BBDDDC 80240C3C 8FBF0010 */  lw        $ra, 0x10($sp)
/* BBDDE0 80240C40 24020002 */  addiu     $v0, $zero, 2
/* BBDDE4 80240C44 03E00008 */  jr        $ra
/* BBDDE8 80240C48 27BD0018 */   addiu    $sp, $sp, 0x18

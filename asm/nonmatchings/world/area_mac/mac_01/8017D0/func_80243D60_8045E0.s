.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243D60_8045E0
/* 8045E0 80243D60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8045E4 80243D64 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8045E8 80243D68 8C82000C */  lw        $v0, 0xc($a0)
/* 8045EC 80243D6C 0C0B1EAF */  jal       get_variable
/* 8045F0 80243D70 8C450000 */   lw       $a1, ($v0)
/* 8045F4 80243D74 0040182D */  daddu     $v1, $v0, $zero
/* 8045F8 80243D78 10600012 */  beqz      $v1, .L80243DC4
/* 8045FC 80243D7C 0000202D */   daddu    $a0, $zero, $zero
/* 804600 80243D80 8C620000 */  lw        $v0, ($v1)
/* 804604 80243D84 5040000A */  beql      $v0, $zero, .L80243DB0
/* 804608 80243D88 00041080 */   sll      $v0, $a0, 2
/* 80460C 80243D8C 3C058026 */  lui       $a1, 0x8026
/* 804610 80243D90 24A52A70 */  addiu     $a1, $a1, 0x2a70
.L80243D94:
/* 804614 80243D94 24630004 */  addiu     $v1, $v1, 4
/* 804618 80243D98 24840001 */  addiu     $a0, $a0, 1
/* 80461C 80243D9C ACA20000 */  sw        $v0, ($a1)
/* 804620 80243DA0 8C620000 */  lw        $v0, ($v1)
/* 804624 80243DA4 1440FFFB */  bnez      $v0, .L80243D94
/* 804628 80243DA8 24A50004 */   addiu    $a1, $a1, 4
/* 80462C 80243DAC 00041080 */  sll       $v0, $a0, 2
.L80243DB0:
/* 804630 80243DB0 3C018026 */  lui       $at, 0x8026
/* 804634 80243DB4 00220821 */  addu      $at, $at, $v0
/* 804638 80243DB8 AC202A70 */  sw        $zero, 0x2a70($at)
/* 80463C 80243DBC 08090F7B */  j         .L80243DEC
/* 804640 80243DC0 00000000 */   nop      
.L80243DC4:
/* 804644 80243DC4 3C038026 */  lui       $v1, 0x8026
/* 804648 80243DC8 24632A70 */  addiu     $v1, $v1, 0x2a70
/* 80464C 80243DCC 0060282D */  daddu     $a1, $v1, $zero
.L80243DD0:
/* 804650 80243DD0 24820010 */  addiu     $v0, $a0, 0x10
/* 804654 80243DD4 AC620000 */  sw        $v0, ($v1)
/* 804658 80243DD8 24630004 */  addiu     $v1, $v1, 4
/* 80465C 80243DDC 24840001 */  addiu     $a0, $a0, 1
/* 804660 80243DE0 28820070 */  slti      $v0, $a0, 0x70
/* 804664 80243DE4 1440FFFA */  bnez      $v0, .L80243DD0
/* 804668 80243DE8 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80243DEC:
/* 80466C 80243DEC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 804670 80243DF0 24020002 */  addiu     $v0, $zero, 2
/* 804674 80243DF4 03E00008 */  jr        $ra
/* 804678 80243DF8 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B2C_D0625C
/* D0625C 80240B2C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D06260 80240B30 AFB00010 */  sw        $s0, 0x10($sp)
/* D06264 80240B34 3C108024 */  lui       $s0, 0x8024
/* D06268 80240B38 26106B60 */  addiu     $s0, $s0, 0x6b60
/* D0626C 80240B3C AFBF0018 */  sw        $ra, 0x18($sp)
/* D06270 80240B40 AFB10014 */  sw        $s1, 0x14($sp)
/* D06274 80240B44 8E020000 */  lw        $v0, ($s0)
/* D06278 80240B48 14400010 */  bnez      $v0, .L80240B8C
/* D0627C 80240B4C 0080882D */   daddu    $s1, $a0, $zero
/* D06280 80240B50 0C00AB39 */  jal       heap_malloc
/* D06284 80240B54 24040040 */   addiu    $a0, $zero, 0x40
/* D06288 80240B58 AE020000 */  sw        $v0, ($s0)
/* D0628C 80240B5C 0000182D */  daddu     $v1, $zero, $zero
/* D06290 80240B60 0040282D */  daddu     $a1, $v0, $zero
/* D06294 80240B64 0220202D */  daddu     $a0, $s1, $zero
.L80240B68:
/* D06298 80240B68 8C820084 */  lw        $v0, 0x84($a0)
/* D0629C 80240B6C 24840004 */  addiu     $a0, $a0, 4
/* D062A0 80240B70 24630001 */  addiu     $v1, $v1, 1
/* D062A4 80240B74 ACA20000 */  sw        $v0, ($a1)
/* D062A8 80240B78 28620010 */  slti      $v0, $v1, 0x10
/* D062AC 80240B7C 1440FFFA */  bnez      $v0, .L80240B68
/* D062B0 80240B80 24A50004 */   addiu    $a1, $a1, 4
/* D062B4 80240B84 080902F2 */  j         .L80240BC8
/* D062B8 80240B88 00000000 */   nop      
.L80240B8C:
/* D062BC 80240B8C 0000182D */  daddu     $v1, $zero, $zero
/* D062C0 80240B90 0040282D */  daddu     $a1, $v0, $zero
/* D062C4 80240B94 0220202D */  daddu     $a0, $s1, $zero
.L80240B98:
/* D062C8 80240B98 8CA20000 */  lw        $v0, ($a1)
/* D062CC 80240B9C 24A50004 */  addiu     $a1, $a1, 4
/* D062D0 80240BA0 24630001 */  addiu     $v1, $v1, 1
/* D062D4 80240BA4 AC820084 */  sw        $v0, 0x84($a0)
/* D062D8 80240BA8 28620010 */  slti      $v0, $v1, 0x10
/* D062DC 80240BAC 1440FFFA */  bnez      $v0, .L80240B98
/* D062E0 80240BB0 24840004 */   addiu    $a0, $a0, 4
/* D062E4 80240BB4 3C108024 */  lui       $s0, 0x8024
/* D062E8 80240BB8 26106B60 */  addiu     $s0, $s0, 0x6b60
/* D062EC 80240BBC 0C00AB4B */  jal       heap_free
/* D062F0 80240BC0 8E040000 */   lw       $a0, ($s0)
/* D062F4 80240BC4 AE000000 */  sw        $zero, ($s0)
.L80240BC8:
/* D062F8 80240BC8 8FBF0018 */  lw        $ra, 0x18($sp)
/* D062FC 80240BCC 8FB10014 */  lw        $s1, 0x14($sp)
/* D06300 80240BD0 8FB00010 */  lw        $s0, 0x10($sp)
/* D06304 80240BD4 24020002 */  addiu     $v0, $zero, 2
/* D06308 80240BD8 03E00008 */  jr        $ra
/* D0630C 80240BDC 27BD0020 */   addiu    $sp, $sp, 0x20

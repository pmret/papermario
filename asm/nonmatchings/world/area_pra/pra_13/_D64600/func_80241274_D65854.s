.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241274_D65854
/* D65854 80241274 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D65858 80241278 AFBF0010 */  sw        $ra, 0x10($sp)
/* D6585C 8024127C 8C82000C */  lw        $v0, 0xc($a0)
/* D65860 80241280 0C0B1EAF */  jal       get_variable
/* D65864 80241284 8C450000 */   lw       $a1, ($v0)
/* D65868 80241288 0040182D */  daddu     $v1, $v0, $zero
/* D6586C 8024128C 10600012 */  beqz      $v1, .L802412D8
/* D65870 80241290 0000202D */   daddu    $a0, $zero, $zero
/* D65874 80241294 8C620000 */  lw        $v0, ($v1)
/* D65878 80241298 5040000A */  beql      $v0, $zero, .L802412C4
/* D6587C 8024129C 00041080 */   sll      $v0, $a0, 2
/* D65880 802412A0 3C058024 */  lui       $a1, 0x8024
/* D65884 802412A4 24A538E8 */  addiu     $a1, $a1, 0x38e8
.L802412A8:
/* D65888 802412A8 24630004 */  addiu     $v1, $v1, 4
/* D6588C 802412AC 24840001 */  addiu     $a0, $a0, 1
/* D65890 802412B0 ACA20000 */  sw        $v0, ($a1)
/* D65894 802412B4 8C620000 */  lw        $v0, ($v1)
/* D65898 802412B8 1440FFFB */  bnez      $v0, .L802412A8
/* D6589C 802412BC 24A50004 */   addiu    $a1, $a1, 4
/* D658A0 802412C0 00041080 */  sll       $v0, $a0, 2
.L802412C4:
/* D658A4 802412C4 3C018024 */  lui       $at, 0x8024
/* D658A8 802412C8 00220821 */  addu      $at, $at, $v0
/* D658AC 802412CC AC2038E8 */  sw        $zero, 0x38e8($at)
/* D658B0 802412D0 080904C0 */  j         .L80241300
/* D658B4 802412D4 00000000 */   nop      
.L802412D8:
/* D658B8 802412D8 3C038024 */  lui       $v1, 0x8024
/* D658BC 802412DC 246338E8 */  addiu     $v1, $v1, 0x38e8
/* D658C0 802412E0 0060282D */  daddu     $a1, $v1, $zero
.L802412E4:
/* D658C4 802412E4 24820080 */  addiu     $v0, $a0, 0x80
/* D658C8 802412E8 AC620000 */  sw        $v0, ($v1)
/* D658CC 802412EC 24630004 */  addiu     $v1, $v1, 4
/* D658D0 802412F0 24840001 */  addiu     $a0, $a0, 1
/* D658D4 802412F4 2882005B */  slti      $v0, $a0, 0x5b
/* D658D8 802412F8 1440FFFA */  bnez      $v0, .L802412E4
/* D658DC 802412FC ACA0016C */   sw       $zero, 0x16c($a1)
.L80241300:
/* D658E0 80241300 8FBF0010 */  lw        $ra, 0x10($sp)
/* D658E4 80241304 24020002 */  addiu     $v0, $zero, 2
/* D658E8 80241308 03E00008 */  jr        $ra
/* D658EC 8024130C 27BD0018 */   addiu    $sp, $sp, 0x18

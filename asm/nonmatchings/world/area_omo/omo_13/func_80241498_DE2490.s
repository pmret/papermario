.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241498_DE3928
/* DE3928 80241498 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DE392C 8024149C AFB00010 */  sw        $s0, 0x10($sp)
/* DE3930 802414A0 0080802D */  daddu     $s0, $a0, $zero
/* DE3934 802414A4 AFBF0014 */  sw        $ra, 0x14($sp)
/* DE3938 802414A8 8E02000C */  lw        $v0, 0xc($s0)
/* DE393C 802414AC 0C0B1EAF */  jal       get_variable
/* DE3940 802414B0 8C450000 */   lw       $a1, ($v0)
/* DE3944 802414B4 00021140 */  sll       $v0, $v0, 5
/* DE3948 802414B8 AE000084 */  sw        $zero, 0x84($s0)
/* DE394C 802414BC 3C018008 */  lui       $at, 0x8008
/* DE3950 802414C0 00220821 */  addu      $at, $at, $v0
/* DE3954 802414C4 942278F8 */  lhu       $v0, 0x78f8($at)
/* DE3958 802414C8 30420040 */  andi      $v0, $v0, 0x40
/* DE395C 802414CC 10400002 */  beqz      $v0, .L802414D8
/* DE3960 802414D0 24020001 */   addiu    $v0, $zero, 1
/* DE3964 802414D4 AE020084 */  sw        $v0, 0x84($s0)
.L802414D8:
/* DE3968 802414D8 8FBF0014 */  lw        $ra, 0x14($sp)
/* DE396C 802414DC 8FB00010 */  lw        $s0, 0x10($sp)
/* DE3970 802414E0 24020002 */  addiu     $v0, $zero, 2
/* DE3974 802414E4 03E00008 */  jr        $ra
/* DE3978 802414E8 27BD0018 */   addiu    $sp, $sp, 0x18
/* DE397C 802414EC 00000000 */  nop       

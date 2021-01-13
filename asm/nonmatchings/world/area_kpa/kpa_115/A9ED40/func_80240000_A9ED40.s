.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A9ED40
/* A9ED40 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A9ED44 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* A9ED48 80240008 0080802D */  daddu     $s0, $a0, $zero
/* A9ED4C 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* A9ED50 80240010 8E02000C */  lw        $v0, 0xc($s0)
/* A9ED54 80240014 0C0B1EAF */  jal       get_variable
/* A9ED58 80240018 8C450000 */   lw       $a1, ($v0)
/* A9ED5C 8024001C 0040302D */  daddu     $a2, $v0, $zero
/* A9ED60 80240020 3C058016 */  lui       $a1, %hi(gCollisionStatus)
/* A9ED64 80240024 84A5A550 */  lh        $a1, %lo(gCollisionStatus)($a1)
/* A9ED68 80240028 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* A9ED6C 8024002C 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* A9ED70 80240030 10A60004 */  beq       $a1, $a2, .L80240044
/* A9ED74 80240034 24020014 */   addiu    $v0, $zero, 0x14
/* A9ED78 80240038 808300B4 */  lb        $v1, 0xb4($a0)
/* A9ED7C 8024003C 10620006 */  beq       $v1, $v0, .L80240058
/* A9ED80 80240040 00000000 */   nop
.L80240044:
/* A9ED84 80240044 8C820014 */  lw        $v0, 0x14($a0)
/* A9ED88 80240048 3C03FFFF */  lui       $v1, 0xffff
/* A9ED8C 8024004C 00431024 */  and       $v0, $v0, $v1
/* A9ED90 80240050 10400005 */  beqz      $v0, .L80240068
/* A9ED94 80240054 00000000 */   nop
.L80240058:
/* A9ED98 80240058 0C039769 */  jal       set_action_state
/* A9ED9C 8024005C 0000202D */   daddu    $a0, $zero, $zero
/* A9EDA0 80240060 0809002A */  j         .L802400A8
/* A9EDA4 80240064 AE000084 */   sw       $zero, 0x84($s0)
.L80240068:
/* A9EDA8 80240068 54A6000F */  bnel      $a1, $a2, .L802400A8
/* A9EDAC 8024006C AE000084 */   sw       $zero, 0x84($s0)
/* A9EDB0 80240070 808300B4 */  lb        $v1, 0xb4($a0)
/* A9EDB4 80240074 24020014 */  addiu     $v0, $zero, 0x14
/* A9EDB8 80240078 10620005 */  beq       $v1, $v0, .L80240090
/* A9EDBC 8024007C 24020001 */   addiu    $v0, $zero, 1
/* A9EDC0 80240080 10620003 */  beq       $v1, $v0, .L80240090
/* A9EDC4 80240084 24020002 */   addiu    $v0, $zero, 2
/* A9EDC8 80240088 54620008 */  bnel      $v1, $v0, .L802400AC
/* A9EDCC 8024008C AE000084 */   sw       $zero, 0x84($s0)
.L80240090:
/* A9EDD0 80240090 8C820004 */  lw        $v0, 4($a0)
/* A9EDD4 80240094 30420001 */  andi      $v0, $v0, 1
/* A9EDD8 80240098 54400003 */  bnel      $v0, $zero, .L802400A8
/* A9EDDC 8024009C AE000084 */   sw       $zero, 0x84($s0)
/* A9EDE0 802400A0 24020001 */  addiu     $v0, $zero, 1
/* A9EDE4 802400A4 AE020084 */  sw        $v0, 0x84($s0)
.L802400A8:
/* A9EDE8 802400A8 24020002 */  addiu     $v0, $zero, 2
.L802400AC:
/* A9EDEC 802400AC 8FBF0014 */  lw        $ra, 0x14($sp)
/* A9EDF0 802400B0 8FB00010 */  lw        $s0, 0x10($sp)
/* A9EDF4 802400B4 03E00008 */  jr        $ra
/* A9EDF8 802400B8 27BD0018 */   addiu    $sp, $sp, 0x18

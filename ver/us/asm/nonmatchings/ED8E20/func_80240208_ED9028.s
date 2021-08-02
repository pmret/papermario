.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240208_ED9028
/* ED9028 80240208 3C038008 */  lui       $v1, %hi(D_8007C760)
/* ED902C 8024020C 8C63C760 */  lw        $v1, %lo(D_8007C760)($v1)
/* ED9030 80240210 3C014334 */  lui       $at, 0x4334
/* ED9034 80240214 44816000 */  mtc1      $at, $f12
/* ED9038 80240218 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ED903C 8024021C AFBF0014 */  sw        $ra, 0x14($sp)
/* ED9040 80240220 AFB00010 */  sw        $s0, 0x10($sp)
/* ED9044 80240224 00031080 */  sll       $v0, $v1, 2
/* ED9048 80240228 00431021 */  addu      $v0, $v0, $v1
/* ED904C 8024022C 00021080 */  sll       $v0, $v0, 2
/* ED9050 80240230 00431023 */  subu      $v0, $v0, $v1
/* ED9054 80240234 000218C0 */  sll       $v1, $v0, 3
/* ED9058 80240238 00431021 */  addu      $v0, $v0, $v1
/* ED905C 8024023C 000210C0 */  sll       $v0, $v0, 3
/* ED9060 80240240 3C01800C */  lui       $at, %hi(D_800B8DEC)
/* ED9064 80240244 00220821 */  addu      $at, $at, $v0
/* ED9068 80240248 C4208DEC */  lwc1      $f0, %lo(D_800B8DEC)($at)
/* ED906C 8024024C 460C0300 */  add.s     $f12, $f0, $f12
/* ED9070 80240250 0C00AB85 */  jal       dead_clamp_angle
/* ED9074 80240254 0080802D */   daddu    $s0, $a0, $zero
/* ED9078 80240258 4600008D */  trunc.w.s $f2, $f0
/* ED907C 8024025C E6020084 */  swc1      $f2, 0x84($s0)
/* ED9080 80240260 8FBF0014 */  lw        $ra, 0x14($sp)
/* ED9084 80240264 8FB00010 */  lw        $s0, 0x10($sp)
/* ED9088 80240268 24020002 */  addiu     $v0, $zero, 2
/* ED908C 8024026C 03E00008 */  jr        $ra
/* ED9090 80240270 27BD0018 */   addiu    $sp, $sp, 0x18

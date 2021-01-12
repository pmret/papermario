.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel appendGfx_model_group
/* AE394 80117C94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AE398 80117C98 AFBF0010 */  sw        $ra, 0x10($sp)
/* AE39C 80117C9C 94820002 */  lhu       $v0, 2($a0)
/* AE3A0 80117CA0 3C05800A */  lui       $a1, %hi(D_8009A5F4)
/* AE3A4 80117CA4 8CA5A5F4 */  lw        $a1, %lo(D_8009A5F4)($a1)
/* AE3A8 80117CA8 2443FFFF */  addiu     $v1, $v0, -1
/* AE3AC 80117CAC 00021080 */  sll       $v0, $v0, 2
/* AE3B0 80117CB0 00451021 */  addu      $v0, $v0, $a1
/* AE3B4 80117CB4 90460001 */  lbu       $a2, 1($v0)
/* AE3B8 80117CB8 04600009 */  bltz      $v1, .L80117CE0
/* AE3BC 80117CBC 00031080 */   sll      $v0, $v1, 2
/* AE3C0 80117CC0 00452821 */  addu      $a1, $v0, $a1
.L80117CC4:
/* AE3C4 80117CC4 90A20001 */  lbu       $v0, 1($a1)
/* AE3C8 80117CC8 00C2102A */  slt       $v0, $a2, $v0
/* AE3CC 80117CCC 10400005 */  beqz      $v0, .L80117CE4
/* AE3D0 80117CD0 24620001 */   addiu    $v0, $v1, 1
/* AE3D4 80117CD4 2463FFFF */  addiu     $v1, $v1, -1
/* AE3D8 80117CD8 0461FFFA */  bgez      $v1, .L80117CC4
/* AE3DC 80117CDC 24A5FFFC */   addiu    $a1, $a1, -4
.L80117CE0:
/* AE3E0 80117CE0 24620001 */  addiu     $v0, $v1, 1
.L80117CE4:
/* AE3E4 80117CE4 3C018015 */  lui       $at, %hi(D_80153224)
/* AE3E8 80117CE8 AC223224 */  sw        $v0, %lo(D_80153224)($at)
/* AE3EC 80117CEC 0C045F40 */  jal       func_80117D00
/* AE3F0 80117CF0 00000000 */   nop
/* AE3F4 80117CF4 8FBF0010 */  lw        $ra, 0x10($sp)
/* AE3F8 80117CF8 03E00008 */  jr        $ra
/* AE3FC 80117CFC 27BD0018 */   addiu    $sp, $sp, 0x18
